import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

t = int(input())


def testcase():
    n = int(input())
    conn = list(map(int, input().split()))
    connr = {}

    for i in range(n):
        val = conn[i] - 1
        conn[i] = val
        connr.setdefault(val, [])
        connr[val].append(i)

    stk = []
    visited = set()

    def traverse(node):
        if node in visited:
            return
        visited.add(node)
        if node in connr:
            for nnode in connr[node]:
                if nnode not in visited:
                    traverse(nnode)
        stk.append(node)

    for i in range(n):
        traverse(i)

    visited = set()
    ret = 0

    def explore(node):
        if node in visited:
            return
        visited.add(node)
        explore(conn[node])

    i = len(stk) - 1
    while i >= 0:
        node = stk[i]
        i -= 1
        if node in visited:
            continue
        if conn[node] in visited and conn[node] != node:
            ret += 1
        explore(node)

    print(ret)


for _ in range(t):
    testcase()
