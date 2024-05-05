n = int(input())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))

backable = {0: (1, 2), 1: (0, 2), 2: (0, 1)}


def testcase(first):
    dp = [[987654321] * 3 for _ in range(n)]
    dp[0][first] = arr[0][first]
    for i in range(3):
        if i != first:
            dp[1][i] = dp[0][first] + arr[1][i]
    for i in range(2, n - 1):
        for j in range(3):
            for back in backable[j]:
                dp[i][j] = min(dp[i][j], dp[i - 1][back] + arr[i][j])
    ret = 987654321
    for i in range(3):
        if i != first:
            for back in backable[i]:
                ret = min(ret, dp[n - 2][back] + arr[n - 1][i])
    return ret


ret = 987654321
for i in range(3):
    ret = min(ret, testcase(i))

print(ret)
