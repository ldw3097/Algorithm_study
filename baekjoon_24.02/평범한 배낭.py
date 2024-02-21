import sys
input = sys.stdin.readline

n,k = map(int,input().split())

dp = [-1] * (k+1)
dp[0] = 0
for _ in range(n):
    w,v = map(int, input().split())
    for i in range(k, w-1, -1):
        if dp[i-w]>=0 and dp[i-w]+v > dp[i]:
            dp[i] = dp[i-w]+v
print(max(dp))