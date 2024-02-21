a,b = map(int,input().split())
making = {a:1}
from collections import *
dq = deque([a])
while dq:
    i = dq.popleft()
    if i == b:
        print(making[b])
        break
    ia = i*2
    ib = i*10+1
    if ia <=b and (ia not in making or making[ia] > making[i]+1):
        making[ia] = making[i]+1
        dq.append(ia)
    if ib <=b and (ib not in making or making[ib] > making[i]+1):
        making[ib] = making[i]+1
        dq.append(ib)
else:
    print(-1)
    