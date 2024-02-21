import sys
from collections import *
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input())
conn = defaultdict(list)
for _ in range(n-1):
    a, b = map(int, input().split())
    conn[a].append(b)
    conn[b].append(a)

parent = {1:1}
def traverse(n):
    for nextn in conn[n]:
        if nextn not in parent:
            parent[nextn] = n
            traverse(nextn)
traverse(1)
for i in range(2,n+1):
    print(parent[i])