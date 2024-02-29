r,c,t = map(int,input().split())
room = []
for _ in range(r):
    room.append(list(map(int, input().split())))

def getcleaner():
    for y in range(r):
        for x in range(c):
            if room[y][x] == -1:
                return (y,x)

py,px = getcleaner()

def diffuse():
    where = []
    for y in range(r):
        for x in range(c):
            if room[y][x] >= 5:
                where.append((y,x,room[y][x]))
    for y,x,m in where:
        a = m // 5
        for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
            ny,nx = y+dy, x+dx
            if 0<=ny<r and 0<=nx<c and room[ny][nx] != -1:
                room[ny][nx] += a
                room[y][x] -= a
    
def movey(to, fr, x):
    direction = 1 if to<fr else -1
    for y in range(to,fr, direction):
        if room[y][x] == -1:
            continue
        room[y][x] = room[y+direction][x]

def movex(to, fr, y):
    direction = 1 if to<fr else -1
    for x in range(to,fr, direction):
        if room[y][x+direction] == -1:
            room[y][x] = 0
        else:
            room[y][x] = room[y][x+direction]

def circulate():
    movey(py, 0, 0)
    movex(0, c-1, 0)
    movey(0, py, c-1)
    movex(c-1, 0, py)

    movey(py+1, r-1, 0)
    movex(0, c-1, r-1)
    movey(r-1, py+1, c-1)
    movex(c-1, 0, py+1)

for _ in range(t):
    diffuse()
    circulate()



ret = 0
for row in room:
    ret += sum(row)

ret += 2
print(ret)
