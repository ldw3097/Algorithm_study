n = int(input())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))

dp = [[arr[0][0]] ]
for i in range(1, n):
    dp.append([])
    for j in range(i+1):
        parret = -1
        if j >0:
            parret = max(parret, dp[i-1][j-1])
        if j < i:
            parret = max(parret, dp[i-1][j])
        dp[i].append(parret+arr[i][j])
print(max(dp[n-1]))