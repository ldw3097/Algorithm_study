

n,m,l,k = map(int, input().split())
xset = set()
yset = set()
stars = []
for _ in range(k):
    x,y = map(int, input().split())
    xset.add(x)
    yset.add(y)
    stars.append((x,y))

starlen = len(stars)

def solve():
    ret = starlen
    for tx in xset:
        for ty in yset:
            parret = starlen
            for x,y in stars:
                if tx<=x<=tx+l and ty<=y<=ty+l:
                    parret -= 1
            ret = min(ret, parret)
    print(ret)

solve()