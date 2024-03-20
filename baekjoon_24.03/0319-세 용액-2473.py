from bisect import *

n = int(input())
arr = list(map(int,input().split()))

retval = 98765432100
visited = set()
arr.sort()
for i in range(n-2):
    for j in range(i+1, n-1):
        val = arr[i]+arr[j]
        idx = bisect_left(arr, -val)
        if idx <= j:
            idx = j+1
        idxs = (idx-1, idx)
        for idx in idxs:
            if j<idx<n:
                parret = abs(val + arr[idx])
                if parret < retval:
                    retval = parret
                    ret = (arr[idx], arr[i], arr[j])


ret = sorted(ret)
print(*ret, sep=" ")


