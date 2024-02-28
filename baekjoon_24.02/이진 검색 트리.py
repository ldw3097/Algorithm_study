import sys
lines = sys.stdin.readlines()
sys.setrecursionlimit(10**5)

a = int(lines[0])
tree = [a,-1,-1]
stk = []

def traverse(n, node):
    if n < node[0]:
        if node[1] == -1:
            node[1] = [n,-1,-1]
        else:
            traverse(n, node[1])
    else:
        if node[2] == -1:
            node[2] = [n,-1,-1]
        else:
            traverse(n, node[2])


for i in range(1, len(lines)):
    c = int(lines[i])
    traverse(c, tree)

def postfix(node):
    if node[1] != -1:
        postfix(node[1])
    if node[2] != -1:
        postfix(node[2])
    print(node[0])

postfix(tree)
