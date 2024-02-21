from bisect import *

a,b,c = map(int,input().split())
mult = a
times = 1
mults = {}

while times <= b:
    mults[times] = mult
    mult = mult*mult%c
    times = times*2

multskey = sorted(list(mults))
lefttimes = b
ret = 1
while lefttimes>0:
    ltplace = bisect_right(multskey, lefttimes)-1
    tomult = multskey[ltplace]
    ret = ret * mults[tomult] % c
    lefttimes -= tomult
print(ret)