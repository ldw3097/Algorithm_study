import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**5)

g = int(input())
p = int(input())
nextloc = [i for i in range(g)]


def findloc(i):
    if i == -1:
        return -1
    if nextloc[i] == i:
        return i
    else:
        ret = findloc(nextloc[i])
        nextloc[i] = ret
        return ret


for i in range(p):
    inp = int(input()) - 1
    loc = findloc(inp)
    if loc == -1:
        print(i)
        break
    nextloc[loc] -= 1
else:
    print(p)
