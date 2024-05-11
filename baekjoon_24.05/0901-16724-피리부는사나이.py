n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(input())

displace = {"D": (1, 0), "U": (-1, 0), "L": (0, -1), "R": (0, 1)}

roots = [[(-1, -1) for _ in range(m)] for _ in range(n)]
ret = 0


def traverse(visited, y, x):
    global ret
    dy, dx = displace[arr[y][x]]
    ny, nx = dy + y, dx + x
    if (ny, nx) in visited:
        ret += 1
        return (y, x)
    if roots[ny][nx] != (-1, -1):
        roots[y][x] = roots[ny][nx]
        return roots[y][x]
    visited.add((y, x))
    roots[y][x] = traverse(visited, ny, nx)


for y in range(n):
    for x in range(m):
        if roots[y][x] == (-1, -1):
            traverse(set(), y, x)

print(ret)
