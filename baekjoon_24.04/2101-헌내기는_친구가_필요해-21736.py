from collections import *

n, m = map(int, input().split())
campus = []

for i in range(n):
    campus.append(list(input()))
    if "I" in campus[-1]:
        iy = i
        ix = campus[-1].index("I")

visited = {(iy, ix)}
q = deque([(iy, ix)])
ret = 0
while q:
    y, x = q.popleft()
    if campus[y][x] == "P":
        ret += 1
    for dy, dx in zip((1, -1, 0, 0), (0, 0, 1, -1)):
        ny, nx = dy + y, dx + x
        if (
            0 <= ny < n
            and 0 <= nx < m
            and campus[ny][nx] != "X"
            and (ny, nx) not in visited
        ):
            visited.add((ny, nx))
            q.append((ny, nx))

if ret == 0:
    print("TT")
else:
    print(ret)
