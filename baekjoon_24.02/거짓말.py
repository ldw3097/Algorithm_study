n,m = map(int, input().split())
unionset = [i for i in range(n+1)]
know = list(map(int,input().split()))[1:]
for i in know:
    unionset[i] = 0

parties = []
for _ in range(m):
    parties.append( list(map(int,input().split()))[1:] )

def find(a):
    while a != unionset[a]:
        a = unionset[a]
    return a

def union(lst):
    minval = min(lst)
    roots = set()
    for i in lst:
        r = find(i)
        roots.add(r)
        if r < minval:
            minval = r
    for i in roots:
        unionset[i] = minval

for party in parties:
    union(party)

ret = 0
for party in parties:
    for i in party:
        if find(i) == 0:
            break
    else:
        ret += 1

print(ret)