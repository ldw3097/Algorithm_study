from collections import *

n = int(input())
tree = list(map(int, input().split()))
todel = int(input())

t = defaultdict(list)
for i in range(len(tree)):
    if tree[i] == -1:
        root = i
    else:
        t[tree[i]].append(i)

def traverse(i):
    if i == todel:
        return 0
    if i not in t or t[i] == [todel]:
        return 1
    return sum([traverse(j) for j in t[i]])

ret = traverse(root)
print(ret)