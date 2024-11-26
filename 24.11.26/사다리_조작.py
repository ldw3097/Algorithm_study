
n,m,h = map(int, input().split())
linesset = set()
for _ in range(m):
    a,b = map(int, input().split())
    linesset.add((a,b))


def nextplace(y,x):
    if x == n-1:
        return (y+1, 1)
    return (y, x+1)

def exchange(state, x):
    state[x], state[x+1] = state[x+1], state[x]

def setchangeable(changeable, x):
    changeable[x-1], changeable[x+1] = True, True


def traverse(state, changeable, y,x, changes, minchange):
    if (y,x) == (h+1, 1):
        if all(state[i] == i for i in range(1, n+1)):
            return changes
        return 4
    
    ny, nx = nextplace(y,x)
    if (y,x) in linesset:
        exchange(state, x)
        cx1, cx2 = changeable[x-1], changeable[x+1]
        setchangeable(changeable, x)
        ret = traverse(state, changeable, ny, nx, changes, minchange)
        minchange = min(ret, minchange)
        exchange(state, x)
        changeable[x-1], changeable[x+1] = cx1, cx2
        return ret
    ret = 4
    
    if changes < 3 and changes+1 < minchange and changeable[x] and (y, x-1) not in linesset and (y, x+1) not in linesset:
        linesset.add((y,x))
        cx1, cx2 = changeable[x-1], changeable[x+1]
        setchangeable(changeable, x)
        changeable[x] = False
        exchange(state, x)
        ret = traverse(state, changeable, ny, nx, changes+1, minchange)
        minchange = min(ret, minchange)
        linesset.discard((y,x))
        exchange(state, x)
        changeable[x-1], changeable[x], changeable[x+1] = cx1, True, cx2
    ret = min(ret, traverse(state, changeable, ny, nx, changes, minchange))
    return ret

def solve():
    state = list(range(n+1))
    changeable = [True] * (n+1)
    ret = traverse(state, changeable, 1,1,0, 4)
    if ret > 3:
        return -1
    return ret

print(solve())
    
    
