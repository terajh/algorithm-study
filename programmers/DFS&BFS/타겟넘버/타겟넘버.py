cnt = 0
def dfs(num, it, res, t):
    global cnt
    if it >= len(num):
        if res == t:
            cnt = cnt + 1
        return
    dfs(num, it+1, res - num[it], t)
    dfs(num, it+1, res + num[it], t)
    
def solution(numbers, target):
    global cnt
    answer = 0
    dfs(numbers, 0, 0, target)
    return cnt