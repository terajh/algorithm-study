def initPrime():
    prime = [0 for _ in range(10000001)]
    check = [0 for _ in range(10000001)]
    for i in range(2, 10000000):
        if check[i]:
            continue
        check[i] = 1
        prime[i] = 1
        for j in range(i+i, 10000000, i):
            check[j] = 1
    return prime

primes = []
cnt = 0
check = [0 for _ in range(10)]
num_check = [0 for _ in range(10000001)]
def dfs(numbers, res):
    global cnt
    global check
    if res != '' and primes[int(res)] == 1:
        if num_check[int(res)] == 0:
            cnt += 1
            num_check[int(res)] = 1
    
    for i in range(len(numbers)):
        if check[i] == 1:
            continue
        check[i] = 1
        res += numbers[i]  
        dfs(numbers, res)
        res = res[:-1]
        check[i] = 0
    
def solution(numbers):
    global primes
    global cnt
    answer = 0
    primes = initPrime()
    dfs(numbers, '')
    
    # print(cnt)
    return cnt