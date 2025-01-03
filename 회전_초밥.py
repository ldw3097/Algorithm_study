import sys
from collections import defaultdict
input = sys.stdin.readline

n, d, k, c = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))

def getpos(p):
    return (p+n) % n

def solve():
    cus = defaultdict(int)
    for i in range(k):
        fish = arr[i]
        cus[fish] += 1

    ret = len(cus) + (1 if c not in cus else 0)
    for i in range(1,n):
        fish = arr[getpos(i+k-1)]
        cus[fish] += 1
        fish = arr[getpos(i-1)]
        cus[fish] -= 1
        if cus[fish] <= 0:
            cus.pop(fish)
        parret = len(cus) + (1 if c not in cus else 0)
        ret = max(ret, parret)

    print(ret)

solve()

