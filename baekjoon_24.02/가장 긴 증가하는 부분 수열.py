n = int(input())
arr = tuple(map(int, input().split()))

dp = [1001]
for a in arr:
    for i in range(len(dp)-1, -1, -1):
        if dp[i] < a :
            if i == len(dp)-1:
                dp.append(a)
            elif a < dp[i+1]:
                dp[i+1] = a
            break
    else:
        dp[0] = a
print(len(dp))