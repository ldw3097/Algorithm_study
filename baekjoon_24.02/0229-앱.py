n,m = map(int,input().split())
a = list(map(int,input().split()))
c = list(map(int,input().split()))

dp = {m:0}
for i in range(n):
    mem = a[i]
    cost = c[i]
    keys = sorted(dp)
    for k in keys:
        v = dp[k]
        target= 0 if mem >= k else k-mem
        if target not in dp or dp[target] > v+cost:
            dp[target] = v+cost
    
    maxcost = 9876543210
    for k in sorted(dp):
        if dp[k] <maxcost:
            maxcost = dp[k]
        else:
            dp.pop(k)
print(dp[0])