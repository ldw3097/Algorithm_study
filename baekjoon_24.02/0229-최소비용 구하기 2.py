n = int(input())
m = int(input())

from collections import *
conn = defaultdict(set)
dist = {}
for _ in range(m):
    a,b,c = map(int,input().split())
    if b in conn[a]:
        dist[(a,b)] = min(dist[(a,b)], c)
    else:
        conn[a].add(b)
        dist[(a,b)] = c


a,b = map(int,input().split())

parent = {}
import heapq
hq = [(0,a,a)]
visited = set()
while hq:
    val, node, parentnode = heapq.heappop(hq)
    if node in visited:
        continue
    visited.add(node)
    parent[node] = parentnode
    if node == b:
        ret1 = val
        break
    for nextnode in conn[node]:
        nextval = dist[(node,nextnode)]
        if nextnode not in visited:
            heapq.heappush(hq, (val+nextval, nextnode, node))
    
ret3 = []
tmp = b
while parent[tmp] != tmp:
    ret3.append(tmp)
    tmp = parent[tmp]
ret3.append(a)
ret3.reverse()
ret2 = len(ret3)

print(ret1)
print(ret2)
for i in ret3:
    print(i, end=" ")
