from collections import *

s = input()
t = input()


def solve():
    slen = len(s)
    dp = set()
    lasttlen = len(t)
    dq = deque([t])

    def addelem(elem):
        if len(elem) <= slen:
            return
        if elem[-1] == 'A':
            newelem = elem[:-1]
            dp.add(newelem)
            dq.append(newelem)
        if elem[0] == 'B':
            newelem = elem[-1:0:-1]
            dp.add(newelem)
            dq.append(newelem)

    while dq:
        a = dq.popleft()
        if a == s:
            print(1)
            return
        if len(a) < lasttlen:
            lasttlen = len(a)
            dp = set()
        addelem(a)
    print(0)

solve()

