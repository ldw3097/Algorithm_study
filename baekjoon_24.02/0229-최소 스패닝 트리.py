v,e = map(int,input().split())
edges = []
for _ in range(e):
    a,b,c = map(int,input().split())
    edges.append((c,a,b))

edges.sort()

vertex = [i for i in range(v+1)]

def find(i):
    toedit = []
    while vertex[i] != i:
        toedit.append(i)
        i = vertex[i]
    for j in toedit:
        vertex[j] = i
    return i

def union(a,b):
    a = find(a)
    b = find(b)
    vertex[a] = b
    
ret = 0
for c,a,b in edges:
    if find(a) == find(b):
        continue
    ret += c
    union(a,b)

print(ret)
