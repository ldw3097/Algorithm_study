n = int(input())

def sol(xpos, c1, c2, c3):
    ret = 0
    for y in range(n):
        if y not in c1 and (xpos+y) not in c2 and (xpos-y) not in c3:
            if xpos == n-1:
                return 1

            c1n, c2n, c3n = c1.copy(), c2.copy(), c3.copy()
            c1n.add(y)
            c2n.add(xpos+y)
            c3n.add(xpos-y)
            ret += sol(xpos+1, c1n, c2n,c3n)
    return ret

ret = sol(0, set(), set(), set())
print(ret)