from collections import *
from copy import deepcopy

n = int(input())
a = []
for _ in range(n):
        a.append(list(map(int, input().split())))

def solve():
    acopy = deepcopy(a)
    ret = 987654321
    for y in range(n):
        for x in range(n):
            if acopy[y][x] == 1:
                ret = min(ret, closest(acopy, y, x))
    print(ret)
    return


def closest(acopy, y, x):
    dq1 = deque([(y,x)])
    dq2 = deque()
    visited = set([(y,x)])
    while dq1:
        cy, cx = dq1.popleft()
        if a[cy][cx] == 0:
            dq2.append((cy,cx,0))
            continue
        acopy[cy][cx] = 0 
        for dy, dx in zip((1,-1,0,0), (0,0,1,-1)):
            ny,nx = cy+dy, cx+dx
            if 0<=ny<n and 0<=nx<n and (ny, nx) not in visited:
                visited.add((ny,nx))
                dq1.append((ny,nx))

    while dq2:
        cy, cx, cost = dq2.popleft()
        if a[cy][cx] == 1:
            return cost
        for dy, dx in zip((1,-1,0,0), (0,0,1,-1)):
            ny,nx = cy+dy, cx+dx
            if 0<=ny<n and 0<=nx<n and (ny, nx) not in visited:
                visited.add((ny,nx))
                dq2.append((ny,nx,cost+1))


solve()