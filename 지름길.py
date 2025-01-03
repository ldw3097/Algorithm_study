import sys
sys.setrecursionlimit(10**5)

n, d = map(int, input().split())
arr = []
for _ in range(n):
    a,b,c = map(int, input().split())
    if b > d or b-a <= c:
        n -=1
        continue
    arr.append((a,b,c))

arr.sort()

def traverse(cn, cpath):
    if cn == n:
        return d - cpath
    a,b,c = arr[cn]
    if cpath > a:
        return traverse(cn+1, cpath)
    ret1 = traverse(cn+1, b) + c + (a-cpath)
    ret2 = traverse(cn+1, cpath)
    return min(ret1, ret2)

ret = traverse(0, 0)
print(ret)