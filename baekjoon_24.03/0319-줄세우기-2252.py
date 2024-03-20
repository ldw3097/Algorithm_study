import sys
input = sys.stdin.readline

n,m = map(int,input().split())
conn = {}
for _ in range(m):
    a,b = map(int, input().split())
    conn.setdefault(a, [])
    conn[a].append(b)

visited = set()
ret = []
def traverse(node):
    if node in visited:
        return
    if node in conn:
        for nextnode in conn[node]:
            traverse(nextnode)
    ret.append(node)
    visited.add(node)

for i in range(1, n+1):
    traverse(i)

ret.reverse()
print(*ret, sep= " ")
