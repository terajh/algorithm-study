import requests
import json


url = 'https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod'
user_grade = [i for i in range(31)] # problem 1 의 [유저 순위]
user_log = [0 for i in range(31)] 
user_prior = []
user_log_list = [[] for i in range(31)]

def start(pid):
    global url
    x_auth_token = 'cd71599bb6303a1082a84a684cb1a187'
    headers = {
        'X-Auth-Token': x_auth_token, 
        'Content-Type':'application/json'
        }
    params = {'problem':pid}
    req = requests.post('/'.join([url, 'start']), headers=headers, data = json.dumps(params))
    return req.json()

def watingLine(_auth):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'waiting_line']), headers=headers)
    j = req.json()
    return j

def gameResult(_auth):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'game_result']), headers=headers)
    j = req.json()
        
    return j

def userInfo(_auth):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'user_info']), headers=headers)
    j = req.json()
        
    return j

def match(_auth, _commands = []):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    # print("match#####", _commands)
    params = {
        'pairs' : _commands
    }
    req = requests.put('/'.join([url, 'match']), headers=headers, data = json.dumps(params))
    return req.json()

def changeGrade(_auth, _commands = []):
    global url, user_log
    com = []
    if len(_commands) == 0:
        com = [{"id": i, "grade": i} for i in range(30)]
    else:
        # 입력 받은 _commands 를 모두 양수로 update 한 뒤 change_grade 요청
        min_m = 999999

        for idx, grade in enumerate(_commands):
            if idx == 0:
                continue
            if min_m > grade:
                min_m = grade
        if min_m < 0:
            for idx, grade in enumerate(_commands):
                if idx == 0:
                    continue
                _commands[idx] += abs(min_m)
        for idx, grade in enumerate(_commands):
            if idx == 0:
                continue
            com.append({"id":idx, "grade":grade})
    print('change!!', _commands)
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    params = {
        'commands' : com
    }
    req = requests.put('/'.join([url, 'change_grade']), headers=headers, data = json.dumps(params))
    return req.json()

def score(_auth):
    global url
    headers = {
        'Authorization': _auth, 
        'Content-Type':'application/json'
    }
    req = requests.get('/'.join([url, 'score']), headers=headers)
    return req.json()

## lose 보다 큰 놈 반환하는 함수
# def getLoseIdx(won, lose, dif):
#     global user_log_list
#     if len(user_log_list[won]):
#         return won
#     else:
#         for idx, val in enumerate(user_log_list[won]):
#             if val[0] < dif:
#                 if idx == 0:
#                     return won
#                 else:
#                     n_val = user_log_list[won][idx-1][0]
#                     n_i = user_log_list[won][idx-1][1]
#                     return getIdx(n_i, lose, 40 - (n_val - dif))
            

def main(pid):
    global user_grade, user_log, user_prior, user_log_list
    # 정규분포에 맞춰 초기화 : 평균 40000, 표준편차 20000
    if pid == 2:
        user_grade = [40 for _ in range(901)]
        user_log = [0 for _ in range(901)]
        user_log_list = [[] for _ in range(901)]
    elif pid == 1:
        user_grade = [40 for _ in range(31)]
        user_log = [0 for _ in range(31)]
        user_log_list = [[] for _ in range(31)]

    user_grade = list(map(int, user_grade))
    j = start(pid)
    print(j)
    auth = j['auth_key']
    matching_list = []
    for i in range(595):
        j = match(auth, matching_list)
        matching_list = []
        # 여기서 waiting 보고 matching 시키기
        waiting_list = watingLine(auth)['waiting_line']
        while True:
            # 제일 먼저 처리할 앞에 2명 matching 시키기
            if len(waiting_list) <= 1:
                break
            a = waiting_list[0]['id']
            b = waiting_list[1]['id']
            waiting_list.pop(0)
            waiting_list.pop(0)
            
            matching_list.append([a,b])
        # print(matching_list)

        # 끝난 게임 있으면 순서 처리해서 change grade 시켜주기
        game_list = gameResult(auth)['game_result']
        # print(game_list)
        for item in game_list:
            won = item['win']
            lose = item['lose']
            taken = item['taken']

            # fd = False
            # for item in user_log_list[won]:
            #     if item[1] == lose:
            #         fd = True
            #         break
            # if not fd:
            #     user_log_list[won].append([taken, lose])
            #     user_log_list[won].sort(reverse=True)

            # try:
            #     won_i = user_prior.index(won)
            # except:
            #     won_i = -1
            
            # try:
            #     lose_i = user_prior.index(lose)
            # except:
            #     lose_i = -1
            # if len(user_prior) == 0:
            #     user_prior = [won, lose]

            # elif won_i == -1 and lose_i == -1:
            # # 둘다 없는 경우 앞뒤로 들어갈 위치 찾고 넣는다
            #     w_i = 0
            #     for item in user_prior:
            #         # won 보다 작은 놈 찾는다
            #         if w_i != 0:
            #             break
            #         for small_by_won in user_log_list[won]:
            #             if item == small_by_won[1]:
            #                 w_i = user_prior.index(item)
            #                 break
                

            #     l_i = -1
            #     for idx, item in enumerate(user_prior):
            #         # lose 보다 큰놈 찾는다
            #         for val in user_log_list[item]:
            #             if val[1] == lose:
            #                 l_i = idx
            #             break
            #     # 없으면 맨 앞에 넣고 아니면 맨 앞에 넣는다
            #     user_prior.insert(w_i, won)
            #     if l_i == -1:
            #         user_prior.append(lose)
            #     else:
            #         user_prior.insert(l_i + 1, lose)

            # elif won_i == -1 and lose_i != -1:
            #     # 진놈만 기록에 있는 경우
            #     w_i = lose_i - 1
            #     for i in range(lose_i):
            #         # lose 왼쪽에서 won 보다 큰놈 찾는다
            #         for item in user_log_list[user_prior[i]]:
            #             if won == item[1]:
            #                 w_i = i
            #                 break
            #     user_prior.insert(w_i + 1, won)

            # elif won_i != -1 and lose_i == -1:
            #     # 이긴놈만 기록에 있는 경우
            #     l_i = won_i
            #     for i in range(l_i, len(user_prior)):
            #         # won 오른쪽에서 lose 보다 큰놈 찾는다
            #         for item in user_log_list[user_prior[i]]:
            #             if lose == item[1]:
            #                 l_i = i
            #                 break
                        
            #     user_prior.insert(l_i + 1, lose)
            # elif won_i != -1 and lose_i != -1:
            #     # 둘다 기록에 있는 경우
            #     if lose_i < won_i:
            #         tp = user_prior[won_i]
            #         user_prior[won_i] = user_prior[lose_i]
            #         user_prior[lose_i] = tp

            # 결과의 가중치만큼 차이를 벌린다
            tk = int((40 - taken) * 99 / 35 )
            if user_grade[lose] > user_grade[won]:
                user_grade[won] += int(tk * (0.4))
                user_grade[lose] -= int(tk * (0.4))
            else:
                user_grade[won] += int(tk * (0.4))
                user_grade[lose] -= int(tk * (0.4))
            # a_w = abs(user_grade[won] - 40)
            # b_l = abs(40 - user_grade[lose])
            # if a_w + b_l != 0:
            #     user_grade[won] += int(tk * (a_w/(a_w+b_l)))
            #     user_grade[lose] -= int(tk * (b_l/(a_w+b_l)))
            # else:
            #     user_grade[won] += int(tk * (0.5))
            #     user_grade[lose] -= int(tk * (0.5))
            # print(int(tk * (b_l/(a_w+b_l))))
        
        print(i)
        if i > 593:
            changeGrade(auth, user_grade)
        
    print(match(auth))
    print(score(auth))
    return score(auth)

if __name__ == "__main__":
    res = []
    res.append(main(1))
    # res.append(main(2))
    print(res)