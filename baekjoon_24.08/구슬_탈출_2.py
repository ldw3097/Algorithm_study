import sys
sys.setrecursionlimit(10**5)

n,m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(input()))
    
inf = 987654321

def firstmover(direction, rplace, bplace):
    if direction == (1,0):
        if rplace[0] > bplace[0]:
            return 'r'
        return 'b'
    if direction == (-1,0):
        if rplace[0] < bplace[0]:
            return 'r'
        return 'b'
    if direction == (0, 1):
        if rplace[1] > bplace[1]:
            return 'r'
        return 'b'
    if direction == (0, -1):
        if rplace[1] < bplace[1]:
            return 'r'
        return 'b'
    
directions = list(zip((1,-1,0,0), (0,0,1,-1)))
def aftermove(ball, otherball, direction):
    ischanged = False
    while True:
        nextplace = (ball[0]+direction[0], ball[1]+direction[1])
        if arr[nextplace[0]][nextplace[1]] == '#' or nextplace == otherball:
            return ball, ischanged
        if arr[nextplace[0]][nextplace[1]] == 'O':
            return (-1,-1), True
        ball = nextplace
        ischanged = True

def lean(times, rplace, bplace, direction):
    if times == 11:
        return inf
    firstm = firstmover(direction, rplace, bplace)
    changed = False
    if firstm == 'r':
        rplace, ischanged = aftermove(rplace, bplace, direction)
        changed |= ischanged
        bplace, ischanged = aftermove(bplace, rplace, direction)
        changed |= ischanged
    else:
        bplace, ischanged = aftermove(bplace, rplace, direction)
        changed |= ischanged
        rplace, ischanged = aftermove(rplace, bplace, direction)
        changed |= ischanged
    if changed == False:
        return inf
    if bplace == (-1,-1):
        return inf
    if rplace == (-1, -1):
        return times
    ret = inf
    for nextdirection in directions:
        ret = min(ret, lean(times+1, rplace, bplace, nextdirection))
    return ret

def solve():
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 'B':
                bplace = (i,j)
            if arr[i][j] == 'R':
                rplace = (i,j)
    ret = inf
    for direction in directions:
        ret = min(ret, lean(1, rplace, bplace, direction))
    if ret == inf:
        print(-1)
    else:
        print(ret)

solve()