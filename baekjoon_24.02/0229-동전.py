t = int(input())

def solve():
    n = int(input())
    coins = list(map(int, input().split()))
    m = int(input())

    dp = [[0]*(m+1) for _ in range(n)]
    for i in range(m+1):
        if i % coins[0] == 0:
            dp[0][i] = 1
    for i in range(1, n):
        val = coins[i]
        for j in range(m+1):
            dp[i][j] = dp[i-1][j]
            if j >= val:
                dp[i][j] += dp[i][j-val]
    return dp[n-1][m]

for _ in range(t):
    print(solve())

