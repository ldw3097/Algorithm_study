import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)
from collections import *

m = int(input())
mod = 1000000007
ret = 0


def getmod(n,s):
    dp = {}
    dp[1] = n
    def getbx2(pow):
        if pow in dp:
            return dp[pow]
        if pow % 2 == 0:
            ret = getbx2(pow//2) * getbx2(pow//2) % mod
        else:
            ret = getbx2(pow//2) * getbx2(pow//2+1) % mod
        dp[pow] = ret
        return ret
    return s * getbx2(mod-2) % mod
        

for _ in range(m):
    n,s = map(int, input().split())
    ret = (ret + getmod(n,s))% mod

print(ret)