from collections import *

n, k = map(int, input().split())

dq = deque()
dq.append(n)
dp = [987654321]*100001
dp[n] = 0
dp2 = [0] * 100001
dp2[n] = 1


while dq:
    a = dq.popleft()
    b = dp[a]
    c = dp2[a]
    if a == k:
        print(b)
        print(c)
        break
    for i in (a+1, a-1, 2*a):
        if 0<=i<100001:
            if dp[i] == b+1:
                dp2[i] += c
            elif dp[i] > b+1:
                dp[i] = b+1
                dp2[i] = c
                dq.append(i)
    


            