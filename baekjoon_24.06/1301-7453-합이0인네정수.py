from collections import *
import sys

input = sys.stdin.readline

n = int(input())
a, b, c, d = [], [], [], []
for _ in range(n):
    aa, bb, cc, dd = map(int, input().split())
    a.append(aa)
    b.append(bb)
    c.append(cc)
    d.append(dd)


def get_possible(lst1, lst2, output):
    for i in lst1:
        for j in lst2:
            output.setdefault(i + j, 0)
            output[i + j] += 1


ab = {}
cd = {}
get_possible(a, b, ab)
get_possible(c, d, cd)

ret = 0
for ab_elem in ab:
    if -ab_elem in cd:
        ret += ab[ab_elem] * cd[-ab_elem]

print(ret)
