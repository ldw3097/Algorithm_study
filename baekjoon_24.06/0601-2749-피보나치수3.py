import sys

sys.setrecursionlimit(10**5)

n = int(input())
dp = {0: 0, 1: 1, 2: 1, 3: 2, 4: 3}


def calc(x):
    if x in dp:
        return dp[x]
    a = x // 2
    ret = (calc(a) * calc(x - a + 1) + calc(a - 1) * calc(x - a)) % 1000000
    dp[x] = ret
    return ret


print(calc(n))
