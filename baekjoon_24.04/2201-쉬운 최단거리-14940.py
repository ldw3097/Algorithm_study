from collections import *

n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
    if 2 in arr[-1]:
        destY = i
        destX = arr[-1].index(2)

dq = deque([(destY, destX, 0)])
ret = [[-1] * m for _ in range(n)]
ret[destY][destX] = 0

while dq:
    y, x, val = dq.popleft()
    for dy, dx in zip((1, -1, 0, 0), (0, 0, 1, -1)):
        ny, nx = y + dy, x + dx
        if 0 <= ny < n and 0 <= nx < m and arr[ny][nx] == 1 and ret[ny][nx] == -1:
            ret[ny][nx] = val + 1
            dq.append((ny, nx, val + 1))

for y in range(n):
    for x in range(m):
        if arr[y][x] == 0:
            ret[y][x] = 0

for row in ret:
    print(*row)
