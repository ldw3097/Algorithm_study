a, b = map(int, input().split())
dp = [1]
for i in range(1, 60):
    dp.append(2 ** (i - 1) + 2 * dp[-1] - 1)

a = bin(a - 1)[2:]
b = bin(b)[2:]


def calc(val):
    l = len(val) - 1
    ret = 0
    upperones = 0
    for i in range(l + 1):
        if val[i] == "1":
            pos = l - i
            parret = dp[pos] + upperones * (2**pos)
            upperones += 1
            ret += parret
    return ret


ret = calc(b) - calc(a)
print(ret)
