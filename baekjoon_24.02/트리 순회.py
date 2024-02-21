import sys
sys.setrecursionlimit(10**5)

n = int(input())
tree = {}
for _ in range(n):
    a, b, c = input().split()
    tree[a] = (b,c)

def preorder(node):
    print(node, end="")
    for next in tree[node]:
        if next != ".":
            preorder(next)

def inorder(node):
    a,b = tree[node]
    if a != ".":
        inorder(a)
    print(node, end="")
    if b != ".":
        inorder(b)
    
def postorder(node):
    a,b = tree[node]
    if a != ".":
        postorder(a)
    if b != ".":
        postorder(b)
    print(node, end="")
    
preorder("A")
print()
inorder("A")
print()
postorder("A")

