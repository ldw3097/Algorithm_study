from bisect import *

n = int(input())
a = list(map(int, input().split()))

arr = [a[0]]
for i in range(1, n):
    val = a[i]
    if arr[-1] < val:
        arr.append(val)
    else:
        idx = bisect_left(arr, val)
        arr[idx] = val

print(len(arr))
