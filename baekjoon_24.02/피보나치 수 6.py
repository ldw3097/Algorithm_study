n = int(input())
dp = {0:0, 1:1, 2:1, 3:2}
div = 1000000007

def find(a):
    if a in dp:
        return dp[a]
    a2 = a//2
    if a %2 == 0:
        ret = find(a2)*(2*find(a2-1)+find(a2)) %div
    else:
        ret = (find(a2+1)**2 + find(a2)**2) % div
    dp[a] = ret
    return ret

print(find(n))
    