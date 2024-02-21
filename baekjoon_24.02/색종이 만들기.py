import sys
sys.setrecursionlimit(10**6)

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

def isidentical(y,x,size):
    root = arr[y][x]
    for i in range(size):
        for j in range(size):
            if arr[y+i][x+j] != root:
                return False
    return True

ret = [0,0]
def solve(y,x,size):
    if isidentical(y,x,size):
        ret[arr[y][x]] += 1
        return
    nextsize = size//2
    for dy,dx in zip((0,0,nextsize,nextsize), (0,nextsize, 0, nextsize)):
        ny,nx = y+dy, x+dx
        solve(ny,nx,nextsize)

solve(0,0,n)
print(ret[0])
print(ret[1])