str = input()

def solve():
    dp = [i for i in range(1, len(str)+1)]
    for i in range(len(str)*2-1):
        isbetween = i%2
        center = i//2
        makepal(center, isbetween, dp)
    print(dp[-1])

def makepal(center, isbetween, dp):
    left = center
    right = center+1 if isbetween else center
    while left>=0 and right < len(str) \
        and str[left] == str[right]:
        pastval = 0 if left == 0 else dp[left-1]
        dp[right] = min(dp[right], pastval+1)
        left, right = left-1, right+1
    
solve()