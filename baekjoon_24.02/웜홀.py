from collections import *
t = int(input())
inf = 9876543210
def solve():
    n,m,w = map(int,input().split())
    dist = [inf]*(n+1)
    dist[1] = 0

    edges = {}
    for _ in range(m):
        a,b,c = map(int,input().split())
        if (a,b) not in edges or edges[(a,b)] > c:
            edges[(a,b)] = c
            edges[(b,a)] = c
    for _ in range(w):
        a,b,c = map(int,input().split())
        if (a,b) not in edges or edges[(a,b)] > -c:
            edges[(a,b)] = -c
    
    def checkedge():
        ret = False
        for (a,b),c in edges.items():
            if dist[b] > dist[a] + c:
                ret = True
                dist[b] = dist[a]+c
        return ret
    
    for _ in range(n-1):
        checkedge()
    if checkedge():
        print("YES")
    else:
        print("NO")

for _ in range(t):
    solve()
