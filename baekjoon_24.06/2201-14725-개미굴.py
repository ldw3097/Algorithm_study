import sys
sys.setrecursionlimit(10**5)

n = int(input())
root = {}

def init(arr, i, parent):
    if i >= len(arr):
        return
    toadd = arr[i]
    if toadd not in parent:
        parent[toadd] = {}
    init(arr, i+1, parent[toadd])


for _ in range(n):
    inp = input().split()[1:]
    init(inp, 0, root)

def draw(dic, level):
    if dic == {}:
        return
    for key in sorted(dic):
        print("--"*level, end="")
        print(key)
        draw(dic[key], level+1)

draw(root, 0)
