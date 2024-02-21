import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

price = [[-1]*3 for _ in range(n)]
price[0] = arr[0]
for i in range(1,n):
    for j in range(3):
        price[i][j] = min(price[i-1][:j] + price[i-1][j+1:]) + arr[i][j]
print(min(price[n-1]))
