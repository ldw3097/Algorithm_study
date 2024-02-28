from collections import *
import sys
# sys.setrecursionlimit(10**4)
input = sys.stdin.readline

r,c = map(int,input().split())
arr = []
for _ in range(r):
    arr.append(input())

dq = deque()
dq.append((1,0,0, {arr[0][0]}))
ret = 0
visited = defaultdict(set)

def checkvisited(ny,nx, s):
    if (ny,nx) not in visited:
        return False
    if s in visited[(ny,nx)]:
        return True
    return False

while dq:
    d,y,x, s = dq.popleft()
    ret = max(ret, d)
    for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
        ny,nx = y+dy, x+dx
        if 0<=ny<r and 0<=nx<c and arr[ny][nx] not in s :
            if checkvisited(ny,nx,s):
                continue
            visited[(ny,nx)].add(frozenset(s))
            news = s.copy()
            news.add(arr[ny][nx])
            dq.append((d+1, ny,nx, news))

print(ret)

# ret = 0
# visited = defaultdict(list)

# def checkvisited(ny,nx, s):
#     if (ny,nx) not in visited:
#         return False
#     for vs in visited[(ny,nx)]:
#         if vs.issuperset(s):
#             return True
#     return False

# def find(y,x,s):
#     ret = 0
#     for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
#         ny,nx = y+dy, x+dx
#         if 0<=ny<r and 0<=nx<c and arr[ny][nx] not in s and not checkvisited(ny,nx,s):
#             visited[(ny,nx)].append(s)
#             news = s.copy()
#             news.add(arr[ny][nx])
#             ret = max(ret, find(ny,nx,news))
#     return ret + 1

# ret = find(0,0,{arr[0][0]})
# print(ret)

