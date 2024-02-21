n,k = map(int,input().split())
visited = {n,}
import heapq
hq = [(0,n)]
while hq:
    t, p = heapq.heappop(hq)
    if p == k:
        print(t)
        break
    if 2*p <=100000 and 2*p not in visited:
        heapq.heappush(hq, (t,2*p))
        visited.add(2*p)
    if p>0 and p-1 not in visited:
        heapq.heappush(hq, (t+1, p-1))
        visited.add(p-1)
    if p<100000 and p+1 not in visited:
        heapq.heappush(hq, (t+1, p+1))
        visited.add(p+1)
