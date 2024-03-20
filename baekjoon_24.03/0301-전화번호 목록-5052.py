import sys
input = sys.stdin.readline
t = int(input())

def solve():
    n = int(input())
    arr = []
    for _ in range(n):
        arr.append(input()[:-1])
    arr.sort()
    for i in range(n-1):
        a = arr[i]
        b = arr[i+1]
        if b[:len(a)] == a:
            return False
    return True

for _ in range(t):
    if solve():
        print("YES")
    else:
        print("NO")
