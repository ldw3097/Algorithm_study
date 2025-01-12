from collections import *

r,c = map(int, input().split())
maze = []
fire_queue = deque()
jihun_queue = deque()
fire_visited = [[False]*c for _ in range(r)]
jihun_visited = [[False]*c for _ in range(r)]

for y in range(r):
    maze.append(input())
    for x in range(c):
        if maze[y][x] == 'F':
            fire_queue.append((y,x))
            fire_visited[y][x] = True
        elif maze[y][x] == 'J':
            jihun_queue.append((y,x,0))  # (y, x, 시간)
            jihun_visited[y][x] = True


def get_adjacent(y,x):
    for dy, dx in ((0,1),(0,-1),(1,0),(-1,0)):
        ny,nx = y+dy, x+dx
        if 0<=ny<r and 0<=nx<c and maze[ny][nx] != '#':
            yield (ny,nx)


while jihun_queue:
    # 불 확산
    for _ in range(len(fire_queue)):
        fy, fx = fire_queue.popleft()
        for ny, nx in get_adjacent(fy, fx):
            if not fire_visited[ny][nx]:
                fire_visited[ny][nx] = True
                fire_queue.append((ny, nx))
    
    # 지훈 이동
    for _ in range(len(jihun_queue)):
        y, x, time = jihun_queue.popleft()
        # 가장자리에 도달하면 탈출 성공
        if y == 0 or y == r-1 or x == 0 or x == c-1:
            print(time + 1)
            exit(0)
        for ny, nx in get_adjacent(y, x):
            if jihun_visited[ny][nx] or fire_visited[ny][nx]:
                continue
            jihun_visited[ny][nx] = True
            jihun_queue.append((ny, nx, time + 1))

print(solve())
