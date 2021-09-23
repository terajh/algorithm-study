check = []
min_cnt = 100
def can_str(a, b):
    cnt = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            cnt += 1
    return cnt == 1
def dfs(words, cur, target, cnt):
    global min_cnt
    if cur == target:
        min_cnt = min(min_cnt, cnt)
        return
    
    for i in range(len(words)):
        if check[i] == 1:
            continue
        if not can_str(cur, words[i]):
            continue
        check[i] = 1
        dfs(words, words[i], target, cnt+1)
        check[i] = 0

def solution(begin, target, words):
    answer = 0
    global check
    global min_cnt
    check = [0 for _ in range(len(words))]
    dfs(words, begin, target, 0)
    return 0 if (min_cnt == 100) else min_cnt