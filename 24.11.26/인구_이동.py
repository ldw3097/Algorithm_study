from collections import *

n, l, r = map(int, input().split())
land = []
for _ in range(n):
    land.append(list(map(int, input().split())))

def makemove(fed):
    tot = 0
    for y,x in fed:
        tot += land[y][x]
    tot //= len(fed)
    for y,x in fed:
        land[y][x] = tot

def oneday():
    ischanged = False
    visited = set()
    for i in range(n):
        for j in range(n):
            if (i,j) in visited:
                continue
            newfed = []
            dq = deque([(i,j)])
            visited.add((i,j))
            while dq:
                y,x = dq.popleft()
                newfed.append((y,x))
                for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
                    ny,nx = y+dy, x+dx
                    if 0<=ny<n and 0<=nx<n and (ny,nx) not in visited \
                    and l <= abs(land[y][x]-land[ny][nx]) <= r :
                        ischanged = True
                        dq.append((ny, nx))
                        visited.add((ny,nx))
            if len(newfed) > 1:
                makemove(newfed)
    return ischanged

def solve():
    ret = 0
    while oneday():
        ret += 1
    print(ret)
    
solve()