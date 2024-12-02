from bisect import *
from collections import *
import sys
sys.setrecursionlimit(10**6)

n, k = map(int, input().split())
c2xy = defaultdict(list)
inf = 10**8

for _ in range(n):
    x,y,c = map(int, input().split())
    c2xy[c].append((x,y))

def getnewbox(box, newx, newy):
    x1,x2,y1,y2=box
    x1 = min(x1, newx)
    x2 = max(x2, newx)
    y1 = min(y1, newy)
    y2 = max(y2, newy)
    return (x1,x2,y1,y2)

def getboxarea(box):
    x1,x2,y1,y2=box
    return (x2-x1)*(y2-y1)

ret = inf
def dfs(ck,box):
    global ret
    if ck > k:
        ret = min(ret, getboxarea(box))
        return
    for x, y in c2xy[ck]:
        newbox = getnewbox(box, x, y)
        if ret <= getboxarea(newbox):
            continue
        dfs(ck+1, newbox)


def solve():
    dfs(1, (inf, -inf, inf, -inf))
    print(ret)

solve()






# n, k = map(int, input().split())
# c2xy = defaultdict(list)
# inf = 10**8
# yu = xr = -inf
# yf = xl = inf
# yset = set()
# xset = set()

# for _ in range(n):
#     x,y,c = map(int, input().split())
#     c2xy[c].append((x,y))
#     yu = max(yu,y)
#     yf = min(yf,y)
#     xr = max(xr,x)
#     xl = min(xl,x)
#     yset.add(y)
#     xset.add(x)

# yset = sorted(yset)
# xset = sorted(xset)

# def insidebox(box, x, y):
#     yu,yf,xr,xl = box
#     if xl<=x<=xr and yf<=y<=yu:
#         return True
#     return False

# def getnewbox(box):
#     yu,yf,xr,xl = box
#     ret = []
#     yui = bisect_left(yset, yu)
#     yfi = bisect_left(yset, yf)
#     if yui != yfi:
#         ret.append((yset[yui-1], yf, xr, xl))
#         ret.append((yu, yset[yfi+1], xr, xl))
#     xri = bisect_left(xset, xr)
#     xli = bisect_left(xset, xl)
#     if xri != xli:
#         ret.append((yu,yf,xset[xri-1], xl))
#         ret.append((yu,yf,xr, xset[xli+1]))
#     return ret


# def traverse(box,visited):
#     if box in visited:
#         return inf
#     visited.add(box)
#     yu,yf,xr,xl = box
#     for c in c2xy:
#         for x, y in c2xy[c]:
#             if insidebox(box, x, y):
#                 break
#         else:
#             return inf
#     ret = (yu-yf) * (xr-xl)
#     if ret == 0:
#         return ret
#     for newbox in getnewbox(box):
#         ret = min(ret, traverse(newbox, visited))
#     return ret
    

# def solve():
#     ret = traverse((yu,yf,xr,xl), set())
#     print(ret)

# solve()
