from collections import *
import heapq

v = int(input())
conn = defaultdict(list)
for _ in range(v):
    inp = list(map(int, input().split()))
    a = inp[0]
    i = 1
    while inp[i] != -1:
        b,c = inp[i], inp[i+1]
        conn[a].append((b,c))
        i += 2

def getfar(start):
    hq = [(0,start)]
    visited = set()
    farthest = -1
    farn = -1
    while hq:
        dist, n = heapq.heappop(hq)
        if n in visited:
            continue
        visited.add(n)
        farthest = max(farthest, dist)
        farn = n
        for nextn, nextdist in conn[n]:
            if nextn not in visited:
                heapq.heappush(hq, (dist+nextdist, nextn))
    return (farn, farthest)

a, b = getfar(1)
c, d = getfar(a)
print(d)