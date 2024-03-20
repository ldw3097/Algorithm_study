a = input()
b = input()


dp = [[0]*(len(b)) for _ in range(len(a))]

for i in range(len(a)):
    aa = a[i]
    premax = 0

    for j in range(len(b)):
        if aa == b[j]:
            if i == 0 or j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1] + 1
        else:
            up = 0 if i==0 else dp[i-1][j]
            left = 0 if j==0 else dp[i][j-1]
            dp[i][j] = max(up,left)

ret1 = max(dp[len(a)-1])
print(ret1)
def getlcs():
    i = len(a)-1
    j = len(b)-1
    ret = []
    while i >=0 and j >= 0:
        if a[i] == b[j]:
            ret.append(b[j])
            i -= 1
            j -= 1
        else:
            B = -1 if i <= 0 else dp[i-1][j]
            C = -1 if j <= 0 else dp[i][j-1]
            if C>=B:
                j -= 1
            else:
                i -= 1
    ret.reverse()
    return "".join(ret)

print(getlcs())
