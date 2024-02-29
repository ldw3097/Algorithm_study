import sys
input = sys.stdin.readline

n = int(input())

arr = []
for i in range(n):
    a,b = map(int,input().split())
    arr.append((a,b))

dp = [[0]*n for _ in range(n)]

inf = 2**31-1
for i in range(2, n+1):
    for start in range(n-i+1):
        end = start+i-1
        val = inf
        for mid in range(start+1, end+1):
            c = dp[start][mid-1] + dp[mid][end] + \
                arr[start][0]*arr[mid][0]*arr[end][1]
            val = min(val, c)
        dp[start][end] = val

ret= dp[0][n-1]
print(ret)