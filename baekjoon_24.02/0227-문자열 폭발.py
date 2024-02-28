inp = input()
bomb = input()
bomblen = len(bomb)

import sys
sys.setrecursionlimit(10**6+1)

ret = [False]*len(inp)


# -> nextpos
def getsubstr(pos, bombpos):
    whereto = [pos]
    bombpos += 1
    pos += 1

    def returnall():
        for val in whereto:
            ret[val] = True
        return (pos, False)

    while bombpos < bomblen :
        if pos >= len(inp):
            return returnall()
        elif inp[pos] == bomb[0]:
            pos, istrimmed = getsubstr(pos, 0)
            if istrimmed == False:
                return returnall()
        elif inp[pos] != bomb[bombpos]:
            return returnall()
        else:
            whereto.append(pos)
            bombpos += 1
            pos += 1
    # bomb와 일치함
    return (pos, True)

    
def solve():
    pos = 0
    while pos < len(inp):
        if inp[pos] != bomb[0]:
            ret[pos] = True
            pos += 1
        else:
            pos, _ = getsubstr(pos, 0)

solve()
printret = []
for i in range(len(inp)):
    if ret[i]:
        printret.append(inp[i])
printret = "".join(printret)

if len(printret) == 0:
    print("FRULA")
else:
    print(printret)