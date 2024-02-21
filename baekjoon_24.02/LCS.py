a = input()
b = input()
dp = [0]*len(b)
for aa in a:
    parmax = 0
    for i in range(len(b)):
        if parmax < dp[i]:
            parmax = dp[i]
        elif b[i] == aa:
            dp[i] = parmax+1
print(max(dp))
