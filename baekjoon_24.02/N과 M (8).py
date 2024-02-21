from itertools import *
n,m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

for c in combinations_with_replacement(arr, m):
    for a in c:
        print(a, end=" ")
    print()
