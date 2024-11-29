from collections import *

arr = []
for _ in range(5):
    arr.append(list(input()))

def getnext(y,x):
    ret = []
    for dy, dx in list(zip((1,-1,0,0), (0,0,1,-1))):
        ny, nx = y+dy, x+dx
        if 0<=ny<5 and 0<=nx<5:
            ret.append((ny, nx))
    return ret

def getnum(y,x):
    return y*5+x

def getmask(base, new):
    return base | (1 << new)


def traverse(y,x,visited):
    dq = deque([(0, 7, 4, set(), y, x)])

    ret = 0
    while dq:
        state, left, s_left, poss, y, x = dq.popleft()
        
        newstate = getmask(state, getnum(y,x))
        if newstate in visited:
            continue
        visited.add(newstate)
        left -= 1
        if arr[y][x] == 'S':
            s_left -= 1
        if left < s_left:
            continue
        if left == 0:
            ret += 1
            continue
        
        newposs =  set(getnext(y,x)) | poss
        for ny,nx in newposs:
            dq.append((newstate, left, s_left, newposs, ny, nx))
    return ret




def solve():
    ret = 0
    visited = set()
    for i in range(5):
        for j in range(5):
            if arr[i][j] == 'S':
                ret += traverse(i,j, visited)
    print(ret)

solve()
