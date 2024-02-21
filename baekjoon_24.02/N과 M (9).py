from itertools import *
n,m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

ret = set()
for c in permutations(arr, m):
    ret.add(tuple(c))
    
for c in sorted(ret):
    for a in c:
        print(a,end=" ")
    print()