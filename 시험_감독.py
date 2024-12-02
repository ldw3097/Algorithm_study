n = int(input())
arr = list(map(int, input().split()))
b,c = map(int, input().split())

def solve():
    ret = len(arr)
    for i in arr:
        i -= b
        if i < 0:
            i = 0
        ret += i // c
        if i % c:
            ret += 1
    print(ret)

solve()