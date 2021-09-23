import math

def solution(progresses, speeds):
    answer = []
    
    prev = 0
    cur = 0
    cnt = 0
    for i in range(len(progresses)):
        progresses[i] = int(math.ceil((100 - progresses[i]) / speeds[i]))
    # 7, 3, 9
    for i in range(len(progresses)):
        cur = progresses[i]
        if i == 0:
            cnt = 1
            prev = cur
            continue
        
        if prev < cur:
            answer.append(cnt)
            cnt = 1
            prev = cur
        else:
            cnt = cnt + 1
    
    answer.append(cnt)
    return answer