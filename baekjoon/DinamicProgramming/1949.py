from collections import deque
import sys
sys.setrecursionlimit(10**6)

check = [0] * 10001
dp = [[0,0] for _ in range(10001)]
def dfs(n, path, arr):
    global check, dp

    for i in range(len(path[n])):
        nxt = path[n][i]
        if check[nxt] == 1:
            continue

        check[nxt] = 1
        dfs(nxt, path, arr)

        ### n번째 안쓰는 경우
        dp[n][0] += max(dp[nxt][0], dp[nxt][1])

        ### n번째 쓰는 경우
        dp[n][1] += dp[nxt][0]

    dp[n][1] += arr[n]

def main():
    global check, dp
    n = int(input())
    arr = list(int(x) for x in input().split(" "))
    arr = deque(arr)
    arr.appendleft(0)

    path = [[] for _ in range(n+1)]
    for _ in range(n-1):
        a, b = map(int, input().split(' '))
        path[a].append(b)
        path[b].append(a)
    check[1] = 1
    dfs(1, path, arr)
    print(max(dp[1][0], dp[1][1]))

if __name__ == "__main__":
    main()


