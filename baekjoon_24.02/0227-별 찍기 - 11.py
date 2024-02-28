import sys
sys.setrecursionlimit(10**5)
n = int(input())
ret = [[" "]* (2*n-1) for _ in range(n)]

starpos = [(0,0), (1,-1), (1,1), (2,-2), (2,-1), (2,0), (2,1), (2,2)]

def solve(y,x,line):
    if line == 3:
        for dy,dx in starpos:
            ret[y+dy][x+dx] = "*"
        return
    linediv2 = line//2
    solve(y, x, linediv2)
    solve(y+linediv2, x-linediv2, linediv2)
    solve(y+linediv2, x+linediv2, linediv2)

solve(0, n-1, n)
for line in ret:
    # print(line)
    print("".join(line))
