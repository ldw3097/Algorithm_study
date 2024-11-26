

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
bliz = []
for _ in range(m):
    bliz.append(tuple(map(int, input().split())))
    
postonum = {}
direct = ((-1,0), (1,0), (0,-1), (0,1))
center = ((n+1)//2-1, (n+1)//2-1)



def next(ll, nodenum):
    _, nextnode = ll[nodenum]
    return nextnode

def getnextgroup(ll, startpos):
    val = ll[startpos][0]
    amount = 0
    pos = startpos
    finalpos = pos
    while ll[pos][0] == val:
        finalpos = pos
        pos = next(ll, pos)
        amount += 1
    return amount, val, finalpos

def removenodes(ll, removelist):
    idx = 0
    counter = 0
    while ll[idx][1] != -1:
        val, nextpos = ll[idx]
        if counter + 1 in removelist:
            newnextpos = ll[nextpos][1]
            if newnextpos == -1:
                return
            ll[idx] = [val, newnextpos]
            idx = newnextpos
            counter += 2
        else:
            counter += 1
            idx = nextpos

def explode(ll):
    ret = 0
    isexploded = True
    while isexploded:
        pos = next(ll, 0)
        lastvalidpos = 0
        isexploded = False
        while ll[pos][1] != -1:
            amount, val, finalpos = getnextgroup(ll, pos)
            if amount >= 4:
                pos = next(ll, finalpos)
                isexploded = True
                ret += val*amount
            else:
                
                ll[lastvalidpos][1] = pos
                lastvalidpos = finalpos
                pos = next(ll, finalpos)
        ll[lastvalidpos][1] = pos

    return ret
            
def constructll(ll):
    pos = next(ll, 0)
    newll = [[0, 1]]
    newpos = 1
    while ll[pos][1] != -1 and newpos < n**2:
        amount, val, finalpos = getnextgroup(ll, pos)
        pos = next(ll, finalpos)
        newpos += 1
        newll.append([amount, newpos])
        if newpos < n**2:
            newpos += 1
            newll.append([val, newpos])
    newll.append([-1,-1])
    return newll
            

def doblizzard(ll, bl):
    d,s = bl
    dy, dx = direct[d-1]
    p = center
    removelist = []
    for _ in range(s):
        p = (p[0]+dy, p[1]+dx)
        removelist.append(postonum[p])
    removenodes(ll, removelist)
    ret = explode(ll)
    ll = constructll(ll)
    return ret, ll
    

def solve():
    seq = (3,2,4,1)
    p = center
    ll = [[0, 1]]
    postonum[p] = 0
    
    counter = 0
    inc = 1
    pos = 1
    currentseqidx = 0
    while p[1] >= 0:
        if counter == 2:
            inc += 1
            counter = 0
        counter += 1
        dy, dx = direct[seq[currentseqidx]-1]
        currentseqidx = (currentseqidx+1)%4
        for _ in range(inc):
            p = (p[0]+dy, p[1]+dx)
            if p[1] < 0:
                break
            postonum[p] = pos
            pos += 1
            if arr[p[0]][p[1]] != 0:
                ll.append(  [arr[p[0]][p[1]], pos]  )
    ll.append([-1,-1])

    ret = 0
    for bl in bliz:
        parret, ll = doblizzard(ll, bl)

        ret += parret
    print(ret)
    
solve()
