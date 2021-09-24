from collections import deque


def getO(x, cnt, arr):
    # print(x, cnt)
    if cnt == 0:
        if x == 1:
            return 'm'
        else:
            return 'o'

    if x <= arr[cnt-1]:
        return getO(x, cnt-1, arr)
    elif arr[cnt-1] < x and x <= arr[cnt-1]+ cnt + 3:
        if x == arr[cnt - 1] + 1:
            return 'm'
        else:
            return 'o'
    else:
        return getO(x-arr[cnt-1]-cnt-3, cnt-1,arr)

n = int(input())

arr = [3]
cnt = 1
while True:
    arr.append(arr[-1] * 2 + cnt + 3)
    
    if arr[-1] > n:
        break
    cnt += 1

# print(arr, cnt)
if n <= arr[cnt-1]: 
    print(getO(n, cnt-1, arr))
else:
    print(getO(n, cnt, arr))


