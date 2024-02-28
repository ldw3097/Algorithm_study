import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))

adj = {0:(0,1), 1:(0,1,2), 2:(1,2)}
def getmax():
    current = arr[0]
    for i in range(1, n):
        nexts = [0]*3
        for j in range(3):
            maxval = -1
            for k in adj[j]:
                maxval = max(maxval, current[k])
            nexts[j] = maxval + arr[i][j]
        current = nexts
    return max(current)

def getmin():
    current = arr[0]
    for i in range(1, n):
        nexts = [0]*3
        for j in range(3):
            minval = 987654321
            for k in adj[j]:
                minval = min(minval, current[k])
            nexts[j] = minval + arr[i][j]
        current = nexts
    return min(current)

print(getmax(),getmin())