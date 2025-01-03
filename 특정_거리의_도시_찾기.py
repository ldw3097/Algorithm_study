import heapq

n,m,k,x = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)

def solve():
    inf = -1
    dist = [inf] * (n+1)
    dist[x] = 0
    hq = [(0,x)]

    visited = set()
    while hq:
        d, node = heapq.heappop(hq)
        if node in visited:
            continue
        visited.add(node)
        dist[node] = d
        for nextn in adj[node]:
            if dist[nextn] == inf or dist[nextn] > d+1:
                heapq.heappush(hq, (d+1, nextn))
    
    ret = []
    for i in range(1, n+1):
        if dist[i] == k:
            ret.append(i)
    if ret == []:
        print(-1)
        return
    for a in ret:
        print(a)

solve()