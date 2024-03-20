import sys
sys.setrecursionlimit(10**4)

n = int(input())
conn = []
for _ in range(n):
    conn.append(tuple(map(int,input().split())))

visitedall = 0
for i in range(n):
    visitedall = visitedall | (1<<i)

dp = {}
def getmin(node, visited):
    if visited == visitedall:
        if conn[node][0] == 0:
            return 9876543210
        return conn[node][0]
    if (node, visited) in dp:
        return dp[(node, visited)]
    
    ret = 9876543210
    for i in range(n):
        if conn[node][i] != 0 and not visited & (1 << i):
            newvisit = visited | (1 << i)
            ret = min(ret, conn[node][i] + getmin(i, newvisit))
    dp[(node, visited)] = ret
    return ret

ret = getmin(0, 1)
print(ret)
