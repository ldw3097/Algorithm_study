import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

n, m = map(int, input().split())

def solve():
    u = [i for i in range(n+1)]
    for _ in range(m):
        t, a, b = map(int, input().split())
        if t == 0:
            union(u, a, b)
        else:
            issame(u, a, b)


def union(u, x, y):
    xr = find(u,x)
    yr = find(u,y)
    u[yr] = xr


def find(u, x):
    if u[x] == x:
        return x
    root = find(u, u[x])
    u[x] = root
    return root

def issame(u,x,y):
    if find(u,x) == find(u,y):
        print("YES")
    else:
        print("NO")

solve()