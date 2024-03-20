n = int(input())
arr= list(map(int, input().split()))
from bisect import *

def getminarr(direction):
    if direction == 1:
        rng = range(1, n)
    else:
        rng = range(n-2, -1, -1)
    ret = [1]
    dp = [arr[0] if direction==1 else arr[-1]]
    for i in rng:
        insidx = bisect_left(dp, arr[i])
        if insidx >= len(dp):
            dp.append(arr[i])
        else:
            dp[insidx] = arr[i]
        ret.append(len(dp))

    return ret if direction==1 else list(reversed(ret))
    
def getlongest():
    incarr = getminarr(1)
    decarr = getminarr(-1)
    tot = max([incarr[i] + decarr[i] for i in range(n)])-1
    return tot

ret = getlongest()
print(ret)