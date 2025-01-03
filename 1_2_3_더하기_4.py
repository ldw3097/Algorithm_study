import sys
input = sys.stdin.readline


dp = [0]*10001
dp[0], dp[1], dp[2] = 1,1,2

for i in range(3):
    j = 1
    while True:
        pos = j*3 + i
        if pos > 10000:
            break
        j += 1
        dp[pos] = dp[pos-3] + pos//2 + 1

t = int(input())
for _ in range(t):
    print(dp[int(input())])



