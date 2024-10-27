

n, m, x, y, k = map(int, input().split())
mp = []
for _ in range(n):
    mp.append(list(map(int, input().split())))
    
ord = list(map(int, input().split()))

def solve():
    dice = [0]*7
    pos = (x,y)
    posset = {
        1 : (0,1),
        2: (0,-1),
        3: (-1, 0),
        4: (1,0)
    }
    dstate = (1,2,3)
    moveset = {
        1: lambda a,b,c : (7-c, b, a),
        2: lambda a,b,c : (c, b, 7-a),
        3: lambda a,b,c : (7-b, a, c),
        4: lambda a,b,c : (b, 7-a, c)
    }
    
    for dr in ord:
        dx, dy = posset[dr]
        newpos = (pos[0]+dx, pos[1]+dy)
        if newpos[0] <0 or newpos[0] >= n or newpos[1] < 0 or newpos[1] >= m:
            continue
        pos = newpos
        dstate = moveset[dr](*dstate)
        xpos, ypos = pos
        if mp[xpos][ypos] == 0:
            mp[xpos][ypos] = dice[7-dstate[0]]
        else:
            dice[7-dstate[0]] = mp[xpos][ypos]
            mp[xpos][ypos] = 0
        print(dice[dstate[0]])
        
solve()
        
        