from collections import *

n, m = map(int, input().split())
walls = []
for _ in range(n):
    walls.append(list(map(int, list(input()))))

nearzero = [[0] * m for _ in range(n)]
visited = set()


def get_zero_area(y, x):
    area = 0
    dq = deque([(y, x)])
    boundaryone = set()
    visited.add((y, x))
    while dq:
        y, x = dq.popleft()
        area += 1
        for dy, dx in zip((1, -1, 0, 0), (0, 0, 1, -1)):
            ny, nx = y + dy, x + dx
            if 0 <= ny < n and 0 <= nx < m:
                if walls[ny][nx] == 0 and (ny, nx) not in visited:
                    visited.add((ny, nx))
                    dq.append((ny, nx))
                elif walls[ny][nx] == 1:
                    boundaryone.add((ny, nx))
    for y, x in boundaryone:
        nearzero[y][x] += area


for y in range(n):
    for x in range(m):
        if walls[y][x] == 1:
            nearzero[y][x] += 1
        elif walls[y][x] == 0 and (y, x) not in visited:
            get_zero_area(y, x)


for y in range(n):
    for x in range(m):
        print(nearzero[y][x] % 10, end="")
    print()
