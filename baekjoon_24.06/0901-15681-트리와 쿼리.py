from collections import *
import sys

sys.setrecursionlimit(10**5 + 1)
input = sys.stdin.readline

n, r, q = map(int, input().split())
conn = defaultdict(list)
for _ in range(n - 1):
    a, b = map(int, input().split())
    conn[a].append(b)
    conn[b].append(a)

subvertex = {}


def traverse(node, parent):
    ret = 1
    for connected in conn[node]:
        if connected != parent:
            ret += traverse(connected, node)
    subvertex[node] = ret
    return ret


traverse(r, -1)

for _ in range(q):
    inp = int(input())
    print(subvertex[inp])
