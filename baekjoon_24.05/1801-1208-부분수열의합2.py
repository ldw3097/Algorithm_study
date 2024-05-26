from collections import *

n, s = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()
for i in range(n):
    if arr[i] >= 0:
        break

positive_sum = sum(arr[i:])
under_lim = s - positive_sum

dfd = defaultdict(int)
for j in range(0, i):
    val = arr[j]
    for prev_val in sorted(dfd.keys()):
        new_val = prev_val + val
        if new_val >= under_lim:
            dfd[new_val] += dfd[prev_val]
    if val >= under_lim:
        dfd[val] += 1


for j in range(i, n):
    val = arr[j]
    for prev_val in sorted(dfd.keys(), reverse=True):
        new_val = prev_val + val
        if new_val <= s:
            dfd[new_val] += dfd[prev_val]
    if val <= s:
        dfd[val] += 1

print(dfd[s])
