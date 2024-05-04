n = int(input())
ret = [[" "] * n for _ in range(n)]


def printstar(y, x, nowN):
    if nowN == 1:
        ret[y][x] = "*"
        return
    nowN //= 3
    for dy in range(3):
        for dx in range(3):
            if dy == 1 and dx == 1:
                continue
            printstar(y + dy * nowN, x + dx * nowN, nowN)


printstar(0, 0, n)
for y in range(n):
    for x in range(n):
        print(ret[y][x], end="")
    print()
