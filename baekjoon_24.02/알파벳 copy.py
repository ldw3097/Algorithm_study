from collections import *
import sys
sys.setrecursionlimit(10**4)
input = sys.stdin.readline

r,c = map(int,input().split())
arr = []
for _ in range(r):
    arr.append(input())


ret = 0
visited = defaultdict(set)

def checkvisited(ny,nx, s):
    if (ny,nx) not in visited:
        return False
    if s in visited[(ny,nx)]:
        return True
    return False

def find(y,x,s):
    ret = 0
    for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
        ny,nx = y+dy, x+dx
        if 0<=ny<r and 0<=nx<c and arr[ny][nx] not in s and not checkvisited(ny,nx,s):
            visited[(ny,nx)].add(frozenset(s))
            news = s.copy()
            news.add(arr[ny][nx])
            ret = max(ret, find(ny,nx,news))
    return ret + 1

ret = find(0,0,{arr[0][0]})
print(ret)

