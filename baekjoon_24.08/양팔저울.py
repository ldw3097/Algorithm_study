n = int(input())
w = list(map(int, input().split()))
m = int(input())
q = list(map(int, input().split()))

dp = [[False] * 40001 for _ in range(n+1)]

def construct():
    for i in range(n+1):
        dp[i][0] = True
    for i, weight in enumerate(w):
        i += 1
        for j in range(1, 40001):
            dp[i][j] = dp[i-1][j]
            prev1 = j - weight
            if prev1 >=0 :
                dp[i][j] |= dp[i-1][prev1]
            prev2 = weight - j
            if prev2 >= 0 :
                dp[i][j] |= dp[i-1][prev2]
            prev3 = weight + j
            if 0<=prev3<40000:
                dp[i][j] |= dp[i-1][prev3]
    
def solve():
    construct()
    ret = []
    for qq in q:
        if dp[n][qq]:
            ret.append('Y')
        else:
            ret.append('N')
    print(' '.join(ret))
                
solve()