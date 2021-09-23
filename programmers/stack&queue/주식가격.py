def solution(prices):
    answer = [0 for _ in range(len(prices))]
    
    s = []
    
    for i in range(len(prices)):
        while s and prices[s[-1]] > prices[i]:
            answer[s[-1]] = i - s[-1]
            s.pop()
        s.append(i)
    
    while s:
        answer[s[-1]] = len(prices) - 1 - s[-1]
        s.pop()
    
    return answer