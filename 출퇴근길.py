import sys
from collections import deque
sys.setrecursionlimit(10**5*2)

n,m = map(int, input().split())
adj = [[] for _ in range(n+1)]

for _ in range(m):
    x,y = map(int, input().split())
    adj[x].append(y)

s,t = map(int, input().split())

def traverse(startnode, endnode):
    endable = {endnode, }
    visited = set([startnode])
    inprogress = set([startnode])
    queue = deque([startnode])

    while queue:
        node = queue.popleft()
        # print(node)
        
        checklater = False
        for nextnode in adj[node]:
            if nextnode in endable:
                
                endable.add(node)
            elif nextnode in inprogress:
                # print(f'{nextnode} in inprogress')
                checklater = True
            elif nextnode not in visited:
                # print(f'{nextnode} not in visited')
                visited.add(nextnode)
                inprogress.add(nextnode)
                queue.append(nextnode)
                checklater = True
        if checklater:
            queue.append(node)
        else:
            inprogress.discard(node)
    return endable

def solve():
    stot = traverse(s,t)
    ttos = traverse(t,s)
    ret = stot & ttos
    ret.discard(s)
    ret.discard(t)
    print(len(ret))

solve()


# def traverse(node, visitededge, validnodes):
#     ret = False
#     for nextnode in adj[node]:
#         if nextnode in validnodes:
#             ret = True
#             validnodes.add(node)
#         elif (node, nextnode) not in visitededge:
#             visitededge.add((node, nextnode))
#             ret |= traverse(nextnode, visitededge, validnodes)
#     if ret:
#         validnodes.add(node)
#     return ret

# def solve():
#     stot_set = {t,}
#     ttos_set = {s,}
#     traverse(s, set(), stot_set)
#     traverse(t, set(), ttos_set)
#     ret = stot_set & ttos_set
#     ret.discard(s)
#     ret.discard(t)
#     print(len(ret))

# solve()