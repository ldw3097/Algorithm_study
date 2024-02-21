import sys
input = sys.stdin.readline
t = int(input())
def testcase():
    n = int(input())
    arr = []
    for _ in range(2):
        arr.append(list(map(int, input().split())))
    dp = [[0]*3 for _ in range(n)]
    dp[0] = [arr[0][0], arr[1][0],0]
    for i in range(1,n):
        dp[i][0] = max(dp[i-1][1], dp[i-1][2])+arr[0][i]
        dp[i][1] = max(dp[i-1][0], dp[i-1][2])+arr[1][i]
        dp[i][2] = max(dp[i-1][0], dp[i-1][1])
    print(max(dp[n-1]))

for _ in range(t):
    testcase()
