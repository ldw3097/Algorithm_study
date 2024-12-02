from bisect import *

n = int(input())
arr = list(map(int, input().split()))

def solve():
    ret = 0
    left = []
    right = list(range(1, n+1))
    for i in range(n):
        val = arr[i]
        right.remove(val)
        lefti = bisect_left(left, val)
        for j in range(lefti):
            ret += bisect_left(right, left[j])
        left.append(val)
        left.sort()
    print(ret)

solve()
