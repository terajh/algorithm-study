from collections import deque

check = []
max_path = []
def dfs(cur, path, tickets):
    global max_path, check
    
    if len(path) > len(max_path):
        max_path = path[:]
    
    for i in range((len(tickets))):
        if check[i] == 1:
            continue
        if tickets[i][0] != cur:
            continue
        check[i] = 1
        dfs(tickets[i][1], path + [tickets[i][1]], tickets)
        check[i] = 0
        
        
            
def solution(tickets):
    global max_path, check
    answer = []
    check = [0 for _ in range(len(tickets))]
    tickets.sort()
    
    dfs('ICN', ['ICN'], tickets)
    
    
    return max_path