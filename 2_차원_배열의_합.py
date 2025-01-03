

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

k = int(input())
inputs = []
for _ in range(k):
    inputs.append(list(map(int, input().split())))


def solve():
    sums = [[0]*(m+1) for _ in range(n+1)]
    for y in range(1, n+1):
        for x in range(1, m+1):
            val = sums[y-1][x] + sums[y][x-1] + arr[y-1][x-1] - sums[y-1][x-1]
            sums[y][x] = val
    
    for i,j,x,y in inputs:
        print(sums[x][y] - sums[i-1][y] - sums[x][j-1] + sums[i-1][j-1])
    
solve()

    