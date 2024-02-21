from collections import *
import heapq

n = int(input())

arr = defaultdict(list)
for _ in range(n-1):
    a,b,c = map(int, input().split())
    arr[a].append((b,c))
    arr[b].append((a,c))

def calcdist(start):
    hq = [(0, start)]
    ret = {}
    while hq:
        d, n = heapq.heappop(hq)
        if n in ret:
            continue
        ret[n] = d
        for nextn, nextd in arr[n]:
            if nextn not in ret:
                heapq.heappush(hq, (nextd+d, nextn))
    return ret

def getmax(dist):
    retn, retd = -1,-1
    for n,d in dist.items():
        if d > retd:
            retd = d
            retn = n
    return (retn, retd)

d = calcdist(1)
mn,md = getmax(d)
d = calcdist(mn)
mn2, md2 = getmax(d)
print(md2)



