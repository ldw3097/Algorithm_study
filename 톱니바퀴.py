from collections import deque

wheel = []
for _ in range(4):
    inp = deque( map(int, list(input())) )
    wheel.append(inp)
k = int(input())
actions = []
for _ in range(k):
    actions.append(tuple(map(int, input().split())))

def roll(direction, cognum):
    pwheel = wheel[cognum]
    if direction == 1:
        pwheel.appendleft(pwheel.pop())
    elif direction == -1:
        pwheel.append(pwheel.popleft())
    else:
        raise

def reversedir(dir):
    if dir == 1:
        return -1
    elif dir == -1:
        return 1
    raise

def cogaction(direction, cognum, flowdirs):
    nextcogs = []
    for flowdir in flowdirs:
        nextcognum = cognum + flowdir
        if nextcognum<0 or nextcognum>=4:
            continue
        if flowdir == 1:
            if wheel[cognum][2] != wheel[nextcognum][6]:
                nextcogs.append((nextcognum, [flowdir]))
        elif flowdir == -1:
            if wheel[cognum][6] != wheel[nextcognum][2]:
                nextcogs.append((nextcognum, [flowdir]))
        else:
            raise
    roll(direction, cognum)
    for nextcog in nextcogs:
        cogaction(reversedir(direction), nextcog[0], nextcog[1])


def solve():
    for a,b in actions:
        cogaction(b, a-1, [-1,1])
    ret = 0
    for i, pwheel in enumerate(wheel):
        ret += pwheel[0] * (2**i)
    print(ret)

solve()