r,c,k = map(int, input().split())
arr = []
for _ in range(3):
    arr.append(list(map(int,input().split())))

def linecalc(idx, arr, isrcalc):
    lim = len(arr[0]) if isrcalc else len(arr)
    items = {}
    for i in range(lim):
        item = arr[idx][i] if isrcalc else arr[i][idx]
        if item == 0:
            continue
        items.setdefault(item, 0)
        items[item] += 1
    items = items.items()
    items = sorted(items, key = lambda x: (x[1], x[0]))
    newlist = []
    for item in items:
        newlist.extend(item)
    if len(newlist) > 100:
        newlist = newlist[:100]
    return newlist

def arrcalc(arr):
    isrcalc = (len(arr) >= len(arr[0]))
    newlists = []
    idxlim = len(arr) if isrcalc else len(arr[0])
    for idx in range(idxlim):
        calcret = linecalc(idx, arr, isrcalc)
        if calcret == []:
            break
        newlists.append(calcret)
    maximum = 0
    for newlist in newlists:
        maximum = max(maximum, len(newlist))
    colcnt = maximum if isrcalc else len(newlists)
    rowcnt = len(newlists) if isrcalc else maximum
    newarr = [[0]*colcnt for _ in range(rowcnt)]
    for i, newlist in enumerate(newlists):
        for j, newitem in enumerate(newlist):
            rowpos = i if isrcalc else j
            colpos = j if isrcalc else i
            newarr[rowpos][colpos] = newitem
    return newarr

def casecalc(arr):
    ret = 0
    for i in range(101):
        try:
            if arr[r-1][c-1] == k:
                return i
        except IndexError:
            pass
        arr = arrcalc(arr)

    return -1

def solve():
    ret = casecalc(arr)
    print(ret)

solve()