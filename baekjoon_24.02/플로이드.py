n = int(input())
m = int(input())
inf = 9876543210
dp = [[inf]*(n+1) for _ in range(n+1)]
for i in range(n+1):
    dp[i][i] = 0
for _ in range(m):
    a,b,c = map(int,input().split())
    dp[a][b] = min(dp[a][b], c)

for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            dp[j][k] = min(dp[j][k], dp[j][i]+dp[i][k])

for i in range(1,n+1):
    for j in range(1,n+1):
        if dp[i][j] == inf:
            print(0, end=" ")
        else:
            print(dp[i][j], end=" ")
    print()