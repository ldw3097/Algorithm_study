from itertools import *

n = int(input())
arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

def solve():
    totalsum = 0
    for pararr in arr:
        totalsum += sum(pararr)
    ret = 987654321
    players = list(range(n))

    for occurance in list(combinations(players, n//2)):
        parret = 0
        for duo in combinations(occurance, 2):
            a, b = duo
            parret += arr[a][b] + arr[b][a]
        leftovers = [p for p in players if p not in occurance]
        for duo in combinations(leftovers, 2):
            a, b = duo
            parret -= arr[a][b] + arr[b][a]


        diff = abs(parret)
        ret = min(ret, diff)
    print(ret)

solve()