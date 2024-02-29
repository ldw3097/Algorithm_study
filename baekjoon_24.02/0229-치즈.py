from collections import *
import sys
sys.setrecursionlimit(10**5)

n,m = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

def airfill(y,x):
    arr[y][x] = -1
    for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
        ny,nx = y+dy, x+dx
        if 0<=ny<n and 0<=nx<m and arr[ny][nx] == 0:
            airfill(ny,nx)
    
airfill(0,0)
def istouched(y,x):
    count = 0
    for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
        ny,nx = y+dy, x+dx
        if arr[ny][nx] == -1:
            count += 1
            if count >= 2:
                return True
    return False

def time():
    todel = []
    for y in range(n):
        for x in range(m):
            if arr[y][x] == 1 and istouched(y,x):
                todel.append((y,x))
    if len(todel) == 0:
        return True
    for y,x in todel:
        airfill(y,x)
    return False

ret = 0
while 1:
    parret = time()
    if parret:
        break
    else:
        ret += 1

print(ret)
