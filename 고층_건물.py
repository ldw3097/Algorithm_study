

n = int(input())
arr = list(map(int, input().split()))
inf = 98765432100

def getangle(y1,x1,y2,x2):
    return (y2-y1) / abs(x2-x1)

def solve():
    ret = 0
    for i in range(n):
        parret = 0
        y = arr[i]
        angle = -inf
        for j in range(i-1, -1, -1):
            newangle = getangle(y, i, arr[j], j)
            if newangle > angle:
                parret += 1
                angle = newangle
        angle = -inf
        for j in range(i+1, n):
            newangle = getangle(y, i, arr[j], j)
            if newangle > angle:
                parret += 1
                angle = newangle
        ret = max(ret, parret)
    print(ret)

solve()

