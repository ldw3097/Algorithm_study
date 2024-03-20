import sys
input = sys.stdin.readline
from bisect import *

n,k = map(int,input().split())
jewel = []
bag = []
for _ in range(n):
    a ,b = map(int,input().split())
    jewel.append((-b, a))
for _ in range(k):
    bag.append(int(input()))

bag.sort()
jewel.sort()
nextloc = [i+1 for i in range(k)]
ret = 0
visited = set()

def insertloc(a):
    l = bisect_left(bag, a)
    toedit = []
    while l in visited:
        toedit.append(l)
        l = nextloc[l]

    if l == k:
        for j in toedit:
            nextloc[j] = k
        return False

    for j in toedit:
        nextloc[j] = nextloc[l]
    visited.add(l)
    return True

for b,a in jewel:
    b = -b
    if insertloc(a):
        ret += b
    
print(ret)



