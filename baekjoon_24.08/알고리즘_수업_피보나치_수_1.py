import sys
sys.setrecursionlimit(10**5)

n = int(input())

recdp = [-1]*(n+1)
def getrec(i):
    if i == 1 or i == 2:
        return 1
    if recdp[i] != -1:
        return recdp[i]
    recdp[i] = getrec(i-1) + getrec(i-2)
    return recdp[i]


def solve():
    ret1 = getrec(n)
    ret2 = n-2
    print(f'{ret1} {ret2}')
    
    
solve()