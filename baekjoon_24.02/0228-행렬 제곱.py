from bisect import *
import sys
sys.setrecursionlimit(10**6)

n, b = map(int, input().split())
arr = [tuple(map(int, input().split())) for _ in range(n)] 
arr= tuple(arr)

def first(source):
    return tuple(tuple(source[y][x]%1000 for x in range(n)) for y in range(n))

def multiply(source, target):
    def getval(y,x, source, target):
        ret = 0
        for i in range(n):
            ret += source[y][i] * target[i][x] % 1000
        return ret % 1000
    ret = tuple(tuple(getval(y,x,source, target) for x in range(n)) for y in range(n))
    return ret

def solve():
    dp = {}
    i = 1
    dp[i] = first(arr)
    tmp = first(arr)
    while i <= b:
        i *= 2
        dp[i] = multiply(tmp, tmp)
        tmp = dp[i]
    keys = sorted(dp)
    
    def breakb(b):
        nextdiv = keys[bisect_right(keys, b)-1]
        if nextdiv == b:
            return dp[nextdiv]
        else:
            return multiply(dp[nextdiv] , breakb(b-nextdiv))
    return breakb(b)

ret = solve()
for tup in ret:
    for i in tup:
        print(i, end=" ")
    print()


