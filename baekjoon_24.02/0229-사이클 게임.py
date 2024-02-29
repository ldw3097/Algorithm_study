n,m = map(int, input().split())

parent = [i for i in range(n)]

def find(j):
    toadd = []
    while j != parent[j]:
        toadd.append(j)
        j = parent[j]
    for k in toadd:
        parent[k] = j
    return j

def union(a,b):
    a = find(a)
    b = find(b)
    parent[a] = b

for i in range(1, m+1):
    a, b = map(int, input().split())
    if find(a) == find(b):
        print(i)
        break
    union(a,b)
else:
    print(0)