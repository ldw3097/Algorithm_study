import sys

sys.setrecursionlimit(10**6)

m, n = map(int, input().split())
arr = []
for i in range(m):
    inp = list(map(int, input().split()))
    arr.append(inp)

dp = {(m - 1, n - 1): 1}


def traverse(y, x):
    if (y, x) in dp:
        return dp[(y, x)]
    ret = 0
    for dy, dx in zip((1, -1, 0, 0), (0, 0, 1, -1)):
        ny, nx = y + dy, x + dx
        if 0 <= ny < m and 0 <= nx < n and arr[ny][nx] < arr[y][x]:
            ret += traverse(ny, nx)
    dp[(y, x)] = ret
    return ret


print(traverse(0, 0))
