import sys
input = sys.stdin.readline

n,m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

dp = [ [0]*(n+1) for _ in range(n+1) ]
for y in range(n):
    for x in range(n):
        dp[y+1][x+1] = dp[y][x+1]+dp[y+1][x]-dp[y][x]+arr[y][x]


for _ in range(m):
    x1,y1,x2,y2 = map(int, input().split())
    ret= dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]
    print(ret)
