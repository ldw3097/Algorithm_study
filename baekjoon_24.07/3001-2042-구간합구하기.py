import sys
input = sys.stdin.readline
n,m,k = map(int, input().split())
tree = [0]*(n*4)

def change(node, left, right, loc, val):
    if left == right == loc:
        diff = val - tree[node]
        tree[node] = val
        return diff
    mid = (left+right)//2
    if loc <= mid:
        diff = change(node*2, left, mid, loc, val)
    else:
        diff = change(node*2+1, mid+1, right, loc, val)
    tree[node] += diff
    return diff

def getsum(node, left, right, lb, rb):
    if right < lb or left > rb:
        return 0
    if lb <= left and rb >= right:
        return tree[node]
    mid = (left+right)//2
    return getsum(node*2, left, mid, lb, rb) + getsum(node*2+1, mid+1, right, lb, rb)


for i in range(1, n+1):
    inp = int(input())
    change(1, 1, n, i, inp)

for _ in range(m+k):
    a,b,c = map(int, input().split())
    if a == 1:
        change(1, 1, n, b, c)
    else:
        print(getsum(1, 1, n, b, c))
