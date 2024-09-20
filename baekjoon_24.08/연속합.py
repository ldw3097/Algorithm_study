n = int(input())
arr = list(map(int, input().split()))

def solve():
    ret = arr[0]
    prev = 0
    for i in arr:
        if prev >= 0:
            prev += i
        else:
            prev = i
        ret = max(ret, prev)
    print(ret)
    
solve()