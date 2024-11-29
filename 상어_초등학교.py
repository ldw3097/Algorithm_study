

n = int(input())
likes = []
for _ in range(n**2):
    likes.append(list(map(int, input().split())))

def solve():
    grid = [[0]*(n+2) for _ in range(n+2)]

    for i in range(n+2):
        for j in range(n+2):
            if i == 0 or i == n+1 or j == 0 or j == n+1:
                grid[i][j] = -1

    dirs = list(zip((1,-1,0,0), (0,0,1,-1)))
    favofnum = {}

    for num, *fav in likes:
        val = (-1,-1,-1,-1)
        favofnum[num] = fav

        nearf = 0
        nearv = 0
        for i in range(1, n+1):
            for j in range(1, n+1):
                if grid[i][j] != 0:
                    continue
                for dy,dx in dirs:
                    ny,nx = i+dy, j+dx
                    if grid[ny][nx] == 0:
                        nearv += 1
                    elif grid[ny][nx] in fav:
                        nearf += 1
                newval = (nearf, nearv, -i, -j)
                if newval > val:
                    val = newval
                nearf = 0
                nearv = 0
        y,x = -val[2], -val[3]
        grid[y][x] = num

    favtoscore = (0,1,10,100,1000)
    ret = 0

    for i in range(1, n+1):
        for j in range(1, n+1):
            num = grid[i][j]
            favs = favofnum[num]
            favcount = 0
            for dy,dx in dirs:
                ny,nx = i+dy, j+dx
                if grid[ny][nx] in favs:
                    favcount += 1
            ret += favtoscore[favcount]
    print(ret)

solve()

