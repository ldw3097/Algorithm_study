from collections import *
import heapq

n,m = map(int, input().split())
ltol = defaultdict(list)
for t in range(m):
    a,b = map(int, input().split())
    ltol[a].append((t,b))
    ltol[b].append((t,a))

mq = [(0, 1)]
visited = set()

def getnexttime(t, nt):
    a,b = divmod(t, m)
    if b > nt:
        return (a+1)*m + nt +1
    return a*m + nt +1

while mq:
    t, l = heapq.heappop(mq)
    if l == n:
        print(t)
        quit()
    if l in visited:
        continue
    visited.add(l)
    for nt, nl in ltol[l]:
        if nl in visited:
            continue
        heapq.heappush(mq, (getnexttime(t, nt), nl))
