import sys
input = sys.stdin.readline

n, m = map(int, input().split())
r,c,d = map(int, input().split())
arr  = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
    
def solve():
    ret = 0
    global r,c,d
    def check_around(y,x):
        for dy, dx in list(zip([1,-1,0,0], [0,0,1,-1])):
            ny, nx = dy+y, dx+x
            if arr[ny][nx] == 0:
                return True
        return False
    
    fw = {0: (-1,0), 1:(0,1), 2:(1,0), 3:(0,-1)}
    bw = {0: (1,0), 1:(0,-1), 2:(-1,0), 3:(0,1)}
    
    while True:
        if arr[r][c] == 0:
            ret += 1
            arr[r][c] = -1
        elif check_around(r,c):
            d = (d+3)%4
            dy,dx = fw[d]
            ny,nx = r+dy, c+dx
            if arr[ny][nx] == 0:
                r,c = ny, nx
        else:
            dy, dx = bw[d]
            ny,nx = r+dy, c+dx
            if arr[ny][nx] != 1:
                r,c = ny,nx
            else:
                break
    print(ret)
    return

solve()
    
            