v,e = map(int,input().split())
k = int(input())
inf = 987654321

from collections import *
conn = defaultdict(set)
cost = {}
for _ in range(e):
    a,b,c = map(int,input().split())
    if b in conn[a]:
        cost[(a,b)] = min(cost[(a,b)], c)
    else:
        conn[a].add(b)
        cost[(a,b)] = c
import heapq
hq = [(0,k)]
visited = set()
ret = [inf]*(v+1)
ret[k] = 0
while hq:
    a, n = heapq.heappop(hq)
    if n in visited:
        continue
    ret[n] = a
    visited.add(n)
    for node in conn[n]:
        if node not in visited:
            c = a + cost[(n,node)]
            heapq.heappush(hq, (c, node))

for i in range(1, v+1):
    if ret[i] == inf:
        print("INF")
    else:
        print(ret[i])
