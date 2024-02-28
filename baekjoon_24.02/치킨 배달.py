from itertools import *
from collections import *

n,m = map(int,input().split())
arr=[]
for _ in range(n):
    arr.append(list(map(int,input().split())))

def getadj(y,x):
    visited = set()
    dq = deque()
    dq.append((y,x,0))
    ret = []
    while dq:
        y,x,dist = dq.popleft()
        if arr[y][x] == 2:
            ret.append((dist,y,x))
        for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
            ny,nx = y+dy, x+dx
            if 0<=ny<n and 0<=nx<n and (ny,nx) not in visited:
                dq.append((ny,nx,dist+1))
                visited.add((ny,nx))
    return ret

chicken = []
adj = {}
for y in range(n):
    for x in range(n):
        if arr[y][x] == 2:
            chicken.append((y,x))
        elif arr[y][x] == 1:
            adj[(y,x)] = getadj(y,x)

def getcitydist(chickens):
    ret = 0
    for house in adj.values():
        for dist,y,x in house:
            if (y,x) in chickens:
                ret += dist
                break
    return ret

ret = 9876543210
for chickens in list(combinations(chicken, m)):
    parret = getcitydist(chickens)
    ret = min(ret, parret)

print(ret)








