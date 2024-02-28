from collections import *
import heapq

n, e = map(int, input().split())
conn = defaultdict(list)
for _ in range(e):
    a,b,c = map(int, input().split())
    conn[a].append((b,c))
    conn[b].append((a,c))

v1, v2 = map(int, input().split())
def getmindist(start):
    hq = [(0,start)]
    visited = set()
    ret = [-1]*(n+1)

    while hq:
        d, v = heapq.heappop(hq)
        if v in visited:
            continue
        visited.add(v)
        ret[v] = d
        for b, c in conn[v]:
            if b not in visited:
                heapq.heappush(hq, (d+c, b))
    return ret

fromone = getmindist(1)
fromv1 = getmindist(v1)
fromv2 = getmindist(v2)
onetov1 = fromone[v1]
onetov2 = fromone[v2]
v1tov2 = fromv1[v2]
v1ton = fromv1[n]
v2ton = fromv2[n]
root1 = -1 if (onetov1==-1 or v1tov2==-1 or v2ton==-1) else onetov1+v1tov2+v2ton
root2 = -1 if (onetov2==-1 or v1tov2==-1 or v2ton==-1) else onetov2+v1tov2+v1ton

if root1 == -1:
    if root2 == -1:
        ret = -1
    else:
        ret = root2
else:
    if root2 == -1:
        ret = root1
    else:
        ret = min(root1, root2)

print(ret)
