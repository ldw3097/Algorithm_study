from collections import deque

n, k = map(int, input().split())
arr = list(map(int, input().split()))
turnpoint = n*2

def calcpos(i):
    return (i+turnpoint) % (turnpoint)

def solve():
    upplace, downplace = 0, n-1
    broken = 0
    level = 0
    robots = deque()
    
    def erode(i):
        arr[i] -= 1
        nonlocal broken
        if arr[i] == 0:
            broken += 1
    
    while broken < k:
        level += 1
        upplace, downplace = calcpos(upplace-1), calcpos(downplace-1)
        for _ in range(len(robots)):
            robot = robots.popleft()
            if robot == downplace:
                continue
            nextpos = calcpos(robot+1)
            if nextpos not in robots and arr[nextpos] > 0:
                erode(nextpos)
                if nextpos == downplace:
                    continue
                robots.append(nextpos)
            else:
                robots.append(robot)
        if arr[upplace] > 0:
            robots.append(upplace)
            erode(upplace)
    print(level)
    
solve()
