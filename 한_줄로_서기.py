from itertools import *

n = int(input())
arr = list(map(int, input().split()))

for line in permutations(list(range(1, n+1)), n):
    for i in range(n):
        bigger = 0
        for j in range(i):
            if line[j] > line[i]:
                bigger += 1
        if bigger != arr[line[i]-1]:
            break
    else:
        for i in range(n):
            print(line[i], end=' ')