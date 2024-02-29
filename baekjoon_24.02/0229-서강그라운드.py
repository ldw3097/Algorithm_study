n, m, r = map(int,input().split())
items = tuple(map(int,input().split()))
inf = 987654321
dp = [[inf]*n for _ in range(n)]
for i in range(n):
    dp[i][i] = 0

for _ in range(r):
    a,b,c = map(int,input().split())
    a,b = a-1, b-1
    dp[a][b] = c
    dp[b][a] = c



for i in range(n):
    for j in range(n):
        for k in range(j):
            if dp[j][k] > dp[j][i] + dp[i][k]:
                dp[j][k] = dp[k][j] = dp[j][i] + dp[i][k]

ret = 0
for i in range(n):
    parret = 0
    for j in range(n):
        if dp[i][j] <= m:
            parret += items[j]
    ret = max(ret, parret)

print(ret)