import sys

input = sys.stdin.readline

t = int(input())
n = int(input())
arr1 = tuple(map(int, input().split()))
m = int(input())
arr2 = tuple(map(int, input().split()))

firsts = {}
for i in range(n):
    parsum = 0
    for j in range(i, n):
        parsum += arr1[j]
        firsts.setdefault(parsum, 0)
        firsts[parsum] += 1

ret = 0
for i in range(m):
    parsum = 0
    for j in range(i, m):
        parsum += arr2[j]
        needed = t - parsum
        if needed in firsts:
            ret += firsts[needed]

print(ret)
