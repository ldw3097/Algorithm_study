from bisect import *
import sys
input = sys.stdin.readline

n = int(input())
clist = []
for i in range(n):
    clist.append((input().strip(), i))


def getst(minlen, cclist, ci):
    cc = cclist[ci][0]

    retlen = -1
    validli = ci


    for clen in range(minlen, 101):
        if clen > len(cc):
            break
        li = bisect_left(cclist, (cc[:clen], -1))
        if ci - li == 0:
            break
        retlen = clen
        validli = li
    
    if retlen == -1:
        return None
    
    idxlst = [item[1] for item in cclist[validli:ci+1]]
    idxlst.sort()
    return retlen, idxlst[0], idxlst[1]


def solve():
    sclist =  sorted(clist)
    cminlen = 0
    s,t = 0,1
    for i in range(n-1, -1,-1):
        parret = getst(cminlen, sclist, i)
        if parret is None:
            continue
        newlen, news, newt = parret
        if cminlen < newlen or (news,newt) < (s,t):
            cminlen = newlen
            s,t = news, newt
    
    ret = clist[s][0], clist[t][0]
    print(f'{ret[0]}\n{ret[1]}')


solve()
