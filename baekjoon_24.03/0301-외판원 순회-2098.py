import sys
sys.setrecursionlimit(10**4)

n = int(input())
conn = []
for _ in range(n):
    conn.append(tuple(map(int,input().split())))

visitedall = {i for i in range(n)}

dp = {}
def getmin(node, visited):
    if visited == visitedall:
        if conn[node][0] == 0:
            return 9876543210
        return conn[node][0]
    if (node, frozenset(visited)) in dp:
        return dp[(node, frozenset(visited))]
    
    ret = 9876543210
    for i in range(n):
        if conn[node][i] != 0 and i not in visited:
            newvisit = visited.copy()
            newvisit.add(i)
            ret = min(ret, conn[node][i] + getmin(i, newvisit))
    dp[(node, frozenset(visited))] = ret
    return ret

ret = getmin(0, {0})
print(ret)
