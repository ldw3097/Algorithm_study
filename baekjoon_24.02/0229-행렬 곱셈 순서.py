import sys
input = sys.stdin.readline

n = int(input())

dp = {}
arr = []
for i in range(n):
    a,b = map(int,input().split())
    dp[(i,i+1)]  = (0,a,b)
    arr.append((a,b))

def calcnum(r1, r2):
    return r1[0] + r2[0] + r1[1]*r1[2]*r2[2]

inf = 2**31-1
for i in range(2, n+1):
    for start in range(n-i+1):
        end = start+i
        val = inf
        for mid in range(start+1, end):
            c = calcnum(dp[(start, mid)], dp[(mid,end)])
            val = min(val, c)
        dp[(start, end)] = (val, arr[start][0] , arr[end-1][1] )

ret,_,_ = dp[(0,n)]
print(ret)