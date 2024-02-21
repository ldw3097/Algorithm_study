from collections import *
import heapq

n,m,x = map(int, input().split())
inf = 9876543210
road = [[inf]*(n+1) for _ in range(n+1)]
for i in range(n+1):
    road[i][i] = 0

gofrom = defaultdict(set)
goto = defaultdict(set)
for _ in range(m):
    a,b,c = map(int,input().split())
    road[a][b] = c
    gofrom[a].add(b)
    goto[b].add(a)

ret1 = [inf]*(n+1)
ret1[x] = 0
hq = [(0,x)]
visited = set()
while hq:
    _, a = heapq.heappop(hq)
    if a in visited:
        continue
    visited.add(a)
    for nextn in goto[a]:
        if ret1[nextn] > ret1[a] + road[nextn][a]:
            ret1[nextn] = ret1[a] + road[nextn][a]
            heapq.heappush(hq, (ret1[nextn], nextn))

ret2 = [inf]*(n+1)
ret2[x] = 0
hq = [(0,x)]
visited = set()
while hq:
    _, a = heapq.heappop(hq)
    if a in visited:
        continue
    visited.add(a)
    for nextn in gofrom[a]:
        if ret2[nextn] > ret2[a] + road[a][nextn]:
            ret2[nextn] = ret2[a] + road[a][nextn]
            heapq.heappush(hq, (ret2[nextn], nextn))

ret = [ret1[i]+ret2[i] for i in range(1, n+1)]
print(max(ret))