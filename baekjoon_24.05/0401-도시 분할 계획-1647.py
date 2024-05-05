import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())
hq = []
for i in range(m):
    a, b, c = map(int, input().split())
    heapq.heappush(hq, (c, a, b))

parent = [i for i in range(n + 1)]
ret = 0
recent = 0
selected = 0


def find(node):
    if parent[node] == node:
        return node
    else:
        root = find(parent[node])
        parent[node] = root
        return root


def union(a, b):
    aroot = find(a)
    broot = find(b)
    parent[broot] = aroot


while selected < n - 1:
    c, a, b = heapq.heappop(hq)
    if find(a) != find(b):
        ret += c
        selected += 1
        recent = c
        union(a, b)

print(ret - recent)
