n,m = map(int, input().split())
grid = []
for _ in range(n):
    grid.append(list(map(int, input().split())))

target = []
for _ in range(m):
    y,x = map(int, input().split())
    target.append((y-1,x-1))


def nynx(y,x):
    ret = []
    for dy, dx in list(zip((1,-1,0,0), (0,0,1,-1))):
        ny, nx = y+dy, x+dx
        if 0<=ny<n and 0<=nx<n and grid[ny][nx] == 0:
            ret.append((ny,nx))
    return ret

def to_one_point(ty,tx,route):
    cy,cx = route[-1]
    if (cy,cx) == (ty,tx):
        return [route]
    ret = []
    for ny, nx in nynx(cy, cx):
        if (ny,nx) not in route:
            ret.extend(to_one_point(ty, tx, route + ((ny,nx),) ))
    return ret

def solve():
    y,x = target[0]
    route = ((y,x),)
    ret = [route]
    for i in range(1, m):
        newroute = []
        ty, tx = target[i]
        for prev_route in ret:
            newroute.extend(to_one_point(ty, tx, prev_route))
        ret = newroute
    print(len(ret))

solve()