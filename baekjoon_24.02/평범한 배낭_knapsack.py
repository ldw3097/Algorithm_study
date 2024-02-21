import sys
input = sys.stdin.readline

n,k = map(int,input().split())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))


dp = [[0]*(n+1) for _ in range(k+1)]
for i in range(1,k+1):
    for j in range(1,n+1):
        w, v = arr[j-1]
        if w <= i:
            dp[i][j] = max(dp[i][j-1], dp[i-w][j-1]+v)
        else:
            dp[i][j] = dp[i][j-1]

print(max(dp[k]))