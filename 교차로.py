import sys
input = sys.stdin.readline
from collections import *

n = int(input())
cars = []
wtonum = {'A': 0, 'B': 1, 'C': 2, 'D':3}
for i in range(n):
    t, w = input().split()
    cars.append((int(t),wtonum[w],i))

def isqsempty(qs):
    for q in qs:
        if len(q) != 0:
            return False
    return True

def solve():
    qs = [deque() for _ in range(4)]
    ret = {}
    i = 0
    time = cars[i][0]
    while i < n or not isqsempty(qs):
        while i < n and cars[i][0] == time:
            t,w,intime = cars[i]
            qs[w].append(intime)
            i += 1

        isdeadlock = not isqsempty(qs)
        presence = [len(qs[j]) > 0 for j in range(4)]

        for j in range(4):
            if len(qs[j]) > 0 and not presence[(j+3)%4]:
                car = qs[j].popleft()
                ret[car] = time
                isdeadlock = False

        if isdeadlock:
            for q in qs:
                for car in q:
                    ret[car] = -1
            for j in range(i, n):
                t,w,intime = cars[j]
                ret[intime] = -1
            break

        if isqsempty(qs):
            if i == n:
                break
            time = cars[i][0]
        else:
            time += 1
    
    for i in range(n):
        print(ret[i])

solve()
    
    