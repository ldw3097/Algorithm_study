from collections import *
import sys
input = sys.stdin.readline

def getnext(y,x,n):
    ret = []
    for dy,dx in zip((1,-1,0,0), (0,0,1,-1)):
        ny,nx = y+dy, x+dx
        if 0<=ny<n and 0<=nx<n:
            ret.append((ny,nx))
    return ret

def testcase():
    n = int(input())
    if n == 0:
        return None
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().split())))
    inf = 987654321
    dp = [[inf]*n for _ in range(n)]
    dp[0][0] = arr[0][0]
    q = deque([(0,0)])
    while q:
        y,x = q.popleft()
        for ny,nx in getnext(y,x,n):
            newval = dp[y][x] + arr[ny][nx]
            if newval < dp[ny][nx]:
                dp[ny][nx] = newval
                q.append((ny,nx))
    return dp[n-1][n-1]

def solve():
    i = 1
    while True:
        parret = testcase()
        if parret is None:
            return
        print(f'Problem {i}: {parret}')
        i += 1

solve()