from collections import *

n = int(input())
k = int(input())

apples = set()
for i in range(k):
    y, x = map(int, input().split())
    apples.add((y, x))

l = int(input())
turns = {}
for i in range(l):
    a, b = input().split()
    turns[int(a)] = b


def simulate():
    direction = 0
    dirToActual = {0: (0, 1), 1: (1, 0), 2: (0, -1), 3: (-1, 0)}
    snake = deque([(1, 1)])

    ret = 0
    while True:
        ret += 1
        dy, dx = dirToActual[direction]
        y, x = snake[-1]
        ny, nx = y + dy, x + dx
        if ny <= 0 or ny > n or nx <= 0 or nx > n:
            return ret
        if (ny, nx) in snake:
            return ret
        snake.append((ny, nx))

        if (ny, nx) not in apples:
            snake.popleft()
        else:
            apples.discard((ny, nx))
        if ret in turns:
            if turns[ret] == "D":
                direction = (direction + 1) % 4
            else:
                direction = (direction + 3) % 4


print(simulate())

# 시뮬레이션 문제. 문제를 제대로 이해하는 능력이 필요함.
