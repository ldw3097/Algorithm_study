

n = int(input())
arr = list(map(int, input().split()))

ret = 0
prev = {}
lbound = 0
for i, a in enumerate(arr):
    if a in prev:
        lbound = max(lbound, prev[a]+1)
    prev[a] = i
    ret += i - lbound + 1


print(ret)

