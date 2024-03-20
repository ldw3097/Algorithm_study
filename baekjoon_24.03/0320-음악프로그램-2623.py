from collections import *
import sys
sys.setrecursionlimit(10**4)

n,m = map(int,input().split())
conn = defaultdict(set)
for _ in range(m):
    a, *b = map(int,input().split())
    for i in range(a-1):
        conn[b[i]].add(b[i+1])

visited = set()
inrec = set()
ret = []
invalid = False
def traverse(node):
    global invalid
    if node in inrec:
        invalid = True
        return
    if node in visited:
        return
    inrec.add(node)

    for nextnode in conn[node]:
        traverse(nextnode)
    visited.add(node)
    inrec.discard(node)
    ret.append(node)


for i in range(1, n+1):
    traverse(i)
    if invalid:
        break

if invalid:
    print(0)
else:
    ret.reverse()
    print(*ret, sep="\n")
