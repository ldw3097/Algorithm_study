import sys
input = sys.stdin.readline

n = int(input())

def take(tree, node, left, right, ord):
    tree[node] -= 1
    if left == right:
        return left
    mid = (left+right)//2
    leftval = tree[node*2]
    if ord <= leftval:
        return take(tree, node*2, left, mid, ord)
    else:
        return take(tree, node*2+1, mid+1, right, ord-leftval)
    
def add(tree, node, left, right, place, amount):
    tree[node] += amount
    if left == right:
        return
    mid = (left+right)//2
    if place <= mid:
        add(tree, node*2, left, mid, place, amount)
    else:
        add(tree, node*2+1, mid+1, right, place, amount)
        

def solve():
    tree = [0]*4000000
    for _ in range(n):
        inp = list(map(int, input().split()))
        if inp[0] == 1:
            print(take(tree, 1, 1, 1000000, inp[1]))
        else:
            add(tree, 1, 1, 1000000, inp[1], inp[2])

solve()
    