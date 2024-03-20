import sys
from collections import *
input = sys.stdin.readline

t = int(input())
def testcase():
    n, k = map(int,input().split())
    time = list(map(int,input().split()))
    req = defaultdict(list)
    for i in range(k):
        a,b = map(int,input().split())
        req[b].append(a)
    dp = {}
    w = int(input())

    def gettime(node):
        if node in dp:
            return dp[node]
        maxval = 0
        for adj in req[node]:
            maxval = max(maxval, gettime(adj))
        ret = maxval + time[node-1]
        dp[node] = ret
        return ret
    return gettime(w)

for i in range(t):
    print(testcase())
