import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))
    
def solve():
    dp = [(0,arr[0], arr[0])]
    for i in range(1, n):
        prev = dp[-1]
        first = max(prev[0], prev[1], prev[2])
        second = prev[0]+arr[i]
        third = prev[1]+arr[i]
        dp.append((first, second, third))
    prev = dp[-1]
    ret = max(prev[0], prev[1], prev[2])
    print(ret)
    
solve()
    