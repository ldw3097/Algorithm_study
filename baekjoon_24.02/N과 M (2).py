from itertools import *
n,m = map(int, input().split())

arr = list(range(1,n+1))
for c in combinations(arr, m):
    for a in c:
        print(a, end=" ")
    print()
