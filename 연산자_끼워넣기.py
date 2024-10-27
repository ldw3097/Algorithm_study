from itertools import *

n= int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))


def docalc(x,y,bb):
    if bb == 1:
        return x+y
    if bb == 2:
        return x-y
    if bb == 3:
        return x*y
    if x >= 0:
        return x // y
    return - (-x // y)


def getresult(bset):
    ret = a[0]
    for i, bb in enumerate(bset):
        ret = docalc(ret, a[i+1], bb)
    return ret

def solve():
    
    posible = list(permutations([1]*b[0] + [2]*b[1] + [3]*b[2] + [4]*b[3]))
    maxval = -10**9
    minval = 10**9
    for bset in posible:
        ret = getresult(bset)
        maxval = max(maxval, ret)
        minval = min(minval, ret)
        
    print(maxval)
    print(minval)
    
solve()