import sys

sys.setrecursionlimit(10**5)

t = int(input())


def testcase():
    k = int(input())
    data = tuple(map(int, input().split()))
    dp = [[0] * k for _ in range(k)]

    cumsum = [0]
    for i in range(k):
        cumsum.append(cumsum[-1] + data[i])

    for i in range(2, k + 1):
        for start in range(k - i + 1):
            # print(f"start: {start}, i: {i}")
            dp[start][start + i - 1] = (
                min(
                    dp[start][j - 1] + dp[j][start + i - 1]
                    for j in range(start + 1, start + i)
                )
                + cumsum[start + i]
                - cumsum[start]
            )
    return dp[0][k - 1]


for _ in range(t):
    print(testcase())
