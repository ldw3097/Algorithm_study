n, m = map(int, input().split())
fruit = []
for _ in range(n):
    fruit.append(list(map(int, input().split())))

locs = []
for _ in range(m):
    locs.append(tuple(map(int, input().split())))


dirs = list(zip((1,-1,0,0), (0,0,1,-1)))


def traverse(time, human, visited, currentlocs):
    if time == 3:
        return 0
    ret = -9876543210
    for dy,dx in dirs:
        cy, cx = currentlocs[human]
        ny, nx = dy+cy, dx+cx
        if 0<=ny<n and 0<=nx<n and (ny,nx) not in visited:
            newvalue = fruit[ny][nx]
            visited.add((ny,nx))

            currentlocs[human] = (ny,nx)
            ntime, nhuman = (time, human+1) if human < m-1 else (time+1, 0)
            ret = max(ret, traverse(ntime, nhuman, visited, currentlocs)+ newvalue)
            
            currentlocs[human] = (cy,cx)
            visited.discard((ny,nx))
    return ret



def solve():
    ret = 0
    visited = set()
    currentlocs = []
    for i in range(m):
        y,x = locs[i]
        y,x = y-1, x-1
        ret += fruit[y][x]
        visited.add((y,x))
        currentlocs.append((y,x))
    ret += traverse(0,0,visited, currentlocs)
    print(ret)

solve()