

n = int(input())
arr = []
arr.append(0)
for _ in range(n):
    arr.append(int(input()))

visited = set()
def traverse(target, cvisited):
    if target in visited:
        if target not in cvisited:
            return (-1, [])
        return (target, [])
    visited.add(target)
    cvisited.add(target)
    startchain, ret = traverse(arr[target], cvisited)
    if startchain == target:
        return (-1, ret + [target])
    elif startchain == -1:
        return (-1, ret)
    return (startchain, ret + [target])

def solve():
    ret = []
    for i in range(1,n+1):
        if i in visited:
            continue
        _, parret = traverse(i, set())
        ret += parret
    print(len(ret))
    ret.sort()
    for a in ret:
        print(a)


solve()