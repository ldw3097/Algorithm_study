from collections import *
n,m = map(int, input().split())
walls = []
for i in range(n):
    walls.append(list(map( int, input() )))

dq = deque( [(0,0,0,1)] )
visited = set()
while dq:
    y,x,w,d = dq.popleft()
    if (y,x) == (n-1,m-1):
        print(d)
        break

    for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
        ny,nx = y+dy, x+dx
        if 0<=ny<n and 0<=nx<m:
            if walls[ny][nx] == 0 and (ny,nx,w) not in visited:
                visited.add((ny,nx,w))
                visited.add((ny,nx,1))
                dq.append((ny,nx,w,d+1))
            if walls[ny][nx] == 1 and w == 0 and (ny,nx,1) not in visited:
                visited.add((ny,nx,1))
                dq.append((ny,nx,1,d+1))
else:
    print(-1)
        
    