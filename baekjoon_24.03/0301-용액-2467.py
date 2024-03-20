from bisect import *

n = int(input())
arr = list(map(int,input().split()))

retval = 2000000001

for i in range(n):
    nextloc = bisect_right(arr, -arr[i])
    if i != nextloc and 0<= nextloc < n and abs(arr[i] + arr[nextloc] ) < retval:
        retval = abs(arr[i] + arr[nextloc] )
        ret = (i, nextloc)
    nextloc -= 1
    if i != nextloc and 0<= nextloc < n and abs(arr[i] + arr[nextloc] ) < retval:
        retval = abs(arr[i] + arr[nextloc] )
        ret = (i, nextloc)

ret = sorted(ret)

print( arr[ret[0]] , arr[ret[1]] )

    
