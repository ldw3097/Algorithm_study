n = int(input())
arr= list(map(int, input().split()))

def getminarr(direction):
    if direction == 1:
        rng = range(1, n)
    else:
        rng = range(n-2, -1, -1)
    ret = [1]
    dp = [arr[0] if direction==1 else arr[-1]]
    for i in rng:
        if arr[i] > dp[-1]:
            dp.append(arr[i])
        else:
            for j in range(len(dp)-1, -1, -1):
                if arr[i] <= dp[j]:
                    toedit = j
                else:
                    break
            dp[toedit] = arr[i]
        ret.append(len(dp))
    return ret if direction==1 else list(reversed(ret))
    
def getlongest():
    incarr = getminarr(1)
    decarr = getminarr(-1)
    tot = max([incarr[i] + decarr[i] for i in range(n)])-1
    return tot

ret = getlongest()
print(ret)