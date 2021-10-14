import requests
import json
import math
import random
from collections import deque

url = 'https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users'

max_truck_buffer = 20
move_time = 6

class Trucks:
    def __init__(self, id, _pos, _buf):
        self.pos = [_pos[0], _pos[1]]
        self.buffer = _buf
        self.id = id

    def move(self, new_pos):
        self.pos = new_pos

    def add(self):
        self.buffer += 1

    def remove(self):
        self.buffer -= 1

def start(pid):
    global url
    x_auth_token = '45986a7f79e1fd20c32ad4994f3ad253'
    path = 'start'
    headers = {
        'X-Auth-Token': x_auth_token, 
        'Content-Type':'application/json'
        }
    params = {'problem':pid}
    req = requests.post('/'.join([url, path]), headers=headers, data = json.dumps(params))
    return req.json()

def location(_auth, _pos, _msize):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'locations']), headers=headers)
    j = req.json()
    cnts = [[0 for _ in range(_msize)] for __ in range(_msize)]
    for item in j['locations']:
        tx, ty = _pos[item['id']]
        cnts[tx][ty] = item['located_bikes_count']
        
    return cnts

def trucks(_auth, _pos):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'trucks']), headers=headers)
    _truck = []
    for item in req.json()['trucks']:
        _truck.append(Trucks(item['id'], _pos[item['location_id']], item['loaded_bikes_count'])) 
    return _truck

def simulate(_auth, _commands):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    params = {
        'commands' : _commands
    }
    req = requests.put('/'.join([url, 'simulate']), headers=headers, data = json.dumps(params))
    return req.json()

def score(_auth):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'score']), headers=headers)
    return req.json()

def trans_command(_cur, _nxt):
    tv = _nxt[0] - _cur[0]
    th = _nxt[1] - _cur[1]
    ret = []
    if tv < 0: # 위로 가는 경우
        for _ in range(abs(tv)):
            ret.append(1)
    else: # 아래로 가는 경우
        for _ in range(tv):
            ret.append(3)
    if th < 0: # 왼쪽으로 가는 경우
        for _ in range(abs(th)):
            ret.append(4)
    else: # 오른쪽으로 가는 경우
        for _ in range(th):
            ret.append(2)
    
    return ret

def trans_command_final(_tid, _truck, _cur_loc, _msize, _pos, _command):
    dx = [0, -1, 0, 1, 0]
    dy = [0, 0, 1, 0, -1]
    ret_command = []
    mean = 2

    # 현재 위치
    cx, cy = _truck[_tid].pos[0], _truck[_tid].pos[1]
    # i : 1, 1, 2, 2
    for i in _command:
        ret_command.append(i)
        if len(ret_command) >= 10:
            break
        cx, cy = cx + dx[i], cy + dy[i]
        if _cur_loc[cx][cy] != mean:
            if _cur_loc[cx][cy] > mean:
                next = _cur_loc[cx][cy] - mean
                for _ in range(next):
                    if _truck[_tid].buffer >= 20:
                        break
                    if len(ret_command) >= 10:
                        break
                    _truck[_tid].add()
                    _cur_loc[cx][cy] -= 1
                    ret_command.append(5)
            else:
                next = mean - _cur_loc[cx][cy]
                for j in range(next):
                    if _truck[_tid].buffer == 0:
                        break
                    if len(ret_command) >= 10:
                        break
                    _truck[_tid].remove()
                    _cur_loc[cx][cy] += 1
                    ret_command.append(6)
        _truck[_tid].move([cx, cy])
    return (_tid, _truck, ret_command, _cur_loc[:])


def get_score(_auth, _truck, _cur_loc, _msize, _pos):
    commands = []
    
    cur_loc = _cur_loc[:]
    prev_loc = []
    
    for t in range(720):
        ## 모두 평균 위치로 설정
        dest = [[] for _ in range(len(_truck))]
        for i in range(len(_truck)):
            if abs(math.floor(_msize/2) - _truck[i].pos[0]) < abs(math.floor(_msize/2) - _truck[i].pos[1]):
                dest[i] = [math.floor(_msize/2), _truck[i].pos[1]] 
            else:
                dest[i] = [_truck[i].pos[0], math.floor(_msize/2)] 
        print(dest)
        # commands 비우기
        commands = []
        cur_loc = location(_auth, _pos, _msize)
        min_m = 100000
        max_m = 0
        min_i = [0,0]
        max_i = [0,0]
        emergen = deque()
        # 현재 위치 중 최소 자전거 수, 최대 자전거 수의 위치를 각각 찾는다
        for i in range(_msize):
            for j in range(_msize):
                if min_m > cur_loc[i][j]:
                    min_m = cur_loc[i][j]
                    min_i[0] = i
                    min_i[1] = j
                if max_m < cur_loc[i][j]:
                    max_m = cur_loc[i][j]
                    max_i[0] = i
                    max_i[1] = j
                if cur_loc[i][j] == 0:
                    emergen.appendleft([i,j])
        
        # emergen check 할 놈 처리 -> 최소값 무시
        idx = 0
        print(emergen)
        if len(emergen) > 0:
            for i in range(len(dest)):
                if len(emergen) == 0:
                    break
                
                dest[i][0], dest[i][1] = emergen[0][0], emergen[0][1]
                emergen.popleft()
        # print(dest)

        ## 여기까지 각 truck 목적지가 dest 리스트에 들어가 있으니 이거를 명령어로 변경
        trans_com = [[] for _ in range(len(_truck))]
        for i, pos in enumerate(dest):
            trans_com[i] = trans_command(_truck[i].pos, dest[i])[:]

        # print(cur_loc)
        for i in range(len(_truck)):
            id, _truck, dist, cur_loc = trans_command_final(i, _truck, cur_loc, _msize, _pos, trans_com[i])
            commands.append({"truck_id":id, "command": dist})
        print(t)

        # for t in _truck:
        #     print(t.id, t.buffer, t.pos)
        simulate(_auth, commands)

def main(_pid):
    msize = 5
    # j: column , i : row
    mymap = [[(msize-i-1 + msize*j) for j in range(msize)] for i in range(msize)]
    
    pos = {mymap[i][j] : [i,j] for i in range(msize) for j in range(msize)}
    ############### 문제 1번 ################
    j = start(_pid)
    auth = j['auth_key']

    cur_loc = location(auth, pos, msize)
    truck = trucks(auth, pos)

    get_score(auth, truck, cur_loc, msize, pos)
    print(score(auth))


if __name__ == '__main__':
    main(1)
    
