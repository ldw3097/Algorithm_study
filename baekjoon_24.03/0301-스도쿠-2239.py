from copy import deepcopy
import sys
sys.setrecursionlimit(10**3)


arr = [ list( map(int, input()) ) for _ in range(9)]

def validate(arr,y,x,val):
    if val in arr[y]:
        return False
    for i in range(9):
        if arr[i][x] == val:
            return False
    ystd = y//3*3
    xstd = x//3*3
    for i in range(ystd, ystd+3):
        for j in range(xstd, xstd+3):
            if arr[i][j] == val:
                return False
    return True

def nextloc(y,x):
    x += 1
    if x >= 9:
        y += 1
        x = 0
    return (y,x)


def solve(newarr, y,x):
    if y>=9 :
        return True
    ny,nx = nextloc(y,x)
    if arr[y][x] != 0:
        return solve(newarr,ny,nx)
    for i in range(1, 10):
        if validate(newarr,y,x,i):
            newarr[y][x] = i
            if solve(newarr,ny,nx):
                return True
    newarr[y][x] = 0
    return False

newarr = deepcopy(arr)
solve(newarr,0,0)
for row in newarr:
    for val in row:
        print(val, end="")
    print()