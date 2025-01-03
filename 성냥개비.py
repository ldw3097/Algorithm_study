import heapq

t = int(input())
ts = []
for _ in range(t):
    ts.append(int(input()))


mton = {2:'1', 3:'7', 4:'4', 5:'2', 6:'6', 7: '8' }
mins = mton.copy()

hq = []
for k in mton:
    heapq.heappush(hq, (k, mton[k]))

while hq:
    a,b = heapq.heappop(hq)
    for k in mton:
        m = k + a
        if m > 100:
            continue
        c = mton[k]
        if k == 6:
            n = min(b+'0', '6'+b)
        else:
            n = min(c+b, b+c)
        if m not in mins or (len(n) < len(mins[m])) or \
            (len(n) == len(mins[m]) and n < mins[m]):
            mins[m] = n
            heapq.heappush(hq, (m, n))
        

def getmax(n):
    if n%2 ==1:
        return '7' + '1'*((n-3)//2)
    else:
        return '1'*(n//2)
    
def solve():
    for tt in ts:
        a = mins[tt]
        b = getmax(tt)
        print(f'{a} {b}')

solve()