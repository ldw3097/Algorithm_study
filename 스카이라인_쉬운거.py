from bisect import bisect_right
import sys
input = sys.stdin.readline

n = int(input())
inp = []
for _ in range(n):
    inp.append(tuple(map(int, input().split()))[1])

a = []
ret = 0
for y in inp:
    toins = bisect_right(a, y)
    if toins < len(a):
        ret += len(a) - toins
        a = a[:toins]
    if y > 0 and (len(a) == 0 or a[-1] < y):
        a.append(y)
ret += len(a)

print(ret)
