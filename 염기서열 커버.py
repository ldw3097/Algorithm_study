import sys
sys.setrecursionlimit(10**3)

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(input())

def iscoexistable(s1, s2):
    for i in range(m):
        if s1[i] != '.' and s2[i] != '.' and s1[i] != s2[i]:
            return False
    return True

def traverse(node, coex, prevs, visited):
    visited.add(node)
    for prev in prevs:
        if prev not in coex[node]:
            return
        
    prevs.add(node)

    for nextnode in coex[node]:
        if nextnode not in visited:
            traverse(nextnode, coex, prevs, visited)
    
    return prevs


def getconnset(node, coex):
    ret = set()
    
    for nextnode in coex[node]:
        parret = frozenset(traverse(nextnode, coex, {node, }, {node,}))
        ret.add(parret)
    
    return ret
    
def dfs(connsets, uncovered, i):
    if len(uncovered) == 0:
        return 0
    if i == len(connsets):
        return len(uncovered)
    ret = 9876543210
    for j in range(i, len(connsets)):
        if len(connsets[j] & uncovered) > 0:
            ret = min(ret, dfs(connsets, uncovered - connsets[j], i+1)+1)
    return ret
    

def solve():
    coex = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            if iscoexistable(arr[i], arr[j]):
                coex[i].append(j)
                coex[j].append(i)
    
    connsets = set()
    for i in range(n):
        connsets |= getconnset(i, coex)
    connsets = list(connsets)

    ret = dfs(connsets, set(range(n)), 0)
    print(ret)

solve()

