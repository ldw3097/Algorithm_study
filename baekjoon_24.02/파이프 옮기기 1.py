n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

downleft = {0: (n-1,n-2), 1: (n-2,n-1), 2: (n-2,n-2)}

nextmove = {0: [(0,1,0), (0,1,2)], 1: [(1,0,1), (1,0,2)], 
            2: [(1,1,0), (1,1,1), (1,1,2)] }

space = {0: [(0,0), (0,1)], 1: [(0,0), (1,0)], 2: [(0,0), (0,1), (1,0), (1,1)]}

def isplaceable(y,x,state):
    for dy,dx in space[state]:
        ny,nx = y+dy, x+dx
        if ny<0 or ny>=n or nx<0 or nx>=n or arr[ny][nx] == 1:
            return False
    return True

dp = {}
def solve(y,x,state):
    if (y,x) == downleft[state]:
        return 1
    if (y,x,state) in dp:
        return dp[(y,x,state)]
    ret = 0
    for dy,dx,nextstate in nextmove[state]:
        ny,nx = y+dy, x+dx
        if isplaceable(ny,nx,nextstate):
            ret += solve(ny,nx,nextstate)
    dp[(y,x,state)] = ret
    return ret

ret = solve(0,0,0)
print(ret)

