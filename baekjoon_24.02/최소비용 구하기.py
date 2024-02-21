import sys
from collections import *
import heapq
input = sys.stdin.readline

n = int(input())
m = int(input())
conn = defaultdict(list)
for _ in range(m):
    a,b,c = map(int,input().split())
    conn[a].append((b,c))
s,t = map(int, input().split())

hq = [(0,s)]
visited = set()
while hq:
    dist, node = heapq.heappop(hq)
    if node == t:
        print(dist)
        break
    if node in visited:
        continue
    visited.add(node)
    for a, b in conn[node]:
        heapq.heappush(hq, (dist+b,a))


