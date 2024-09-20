from itertools import *

n, m = map(int, input().split())
arr = list(range(1, n+1))
for j in list(permutations(arr, m)):
    print(' '.join(map(str, j)))
    