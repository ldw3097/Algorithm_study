arr = list(map(int,input().split()))
arr.pop()

def getcost(a,b):
    if a==b:
        return 1
    if a == 0:
        return 2
    if abs(a-b) == 2:
        return 4
    return 3

dp =  {(0,0):0} 

def placeminval(d,key, val):
    if key not in d:
        d[key] = val
        return
    d[key] = min(d[key], val)

for i in arr:
    new = {}
    for (a,b), val in dp.items():
        if i in (a,b):
            placeminval(new,(a,b), val+1)
            continue
        c1 = getcost(a, i)
        newa, newb = max(b,i), min(b,i)
        placeminval(new, (newa, newb), val+c1)

        c2 = getcost(b, i)
        newa, newb = max(a,i), min(a,i)
        placeminval(new, (newa, newb), val+c2)
    dp = new

ret = min(dp.values())
print(ret)



