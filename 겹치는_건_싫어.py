from collections import *
n, k = map(int, input().split())
arr = list(map(int, input().split()))

def solve():
    spos = 0
    epos = 0
    nums = defaultdict(int)
    ret = 0
    while epos < n:
        epos += 1
        a = arr[epos-1]
        nums[a] += 1
        while nums[a] > k:
            b = arr[spos]
            nums[b] -= 1
            spos += 1
        ret = max(ret, epos-spos)
    print(ret)

solve()