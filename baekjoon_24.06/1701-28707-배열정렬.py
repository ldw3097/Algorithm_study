import sys
from collections import *
import heapq

sys.setrecursionlimit(10**5)

n = int(input())
a = list(map(int, input().split()))
m = int(input())
lrc = []
for _ in range(m):
    l, r, c = map(int, input().split())
    lrc.append((l - 1, r - 1, c))

alen = len(a)


def is_not_desc(arr):
    for i in range(1, alen):
        if arr[i] < arr[i - 1]:
            return False
    return True


def swaptup(tup, l, r):
    return tup[:l] + (tup[r],) + tup[l + 1 : r] + (tup[l],) + tup[r + 1 :]


def solve():
    hq = [(0, tuple(a))]
    visited = set()
    while hq:
        cost, tup = heapq.heappop(hq)
        if tup in visited:
            continue
        visited.add(tup)
        if is_not_desc(tup):
            return cost
        for l, r, c in lrc:
            newtup = swaptup(tup, l, r)
            heapq.heappush(hq, (cost + c, newtup))
    return -1


print(solve())
