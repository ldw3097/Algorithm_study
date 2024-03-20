n,s = map(int,input().split())
arr = tuple(map(int,input().split()))

def solve():
    if sum(arr) < s:
        return 0

    arrsum = [0]
    for i in range(n):
        arrsum.append(arrsum[-1]+arr[i])

    def getsum(start, end):
        return arrsum[end] - arrsum[start-1]

    def isable(leng):
        for i in range(1, n-leng+2 ):
            parret = getsum(i, i+leng-1)
            if parret >= s:
                return True
        return False
            
    start = 1
    end = n
    while start < end:
        mid = (start+end)//2
        if isable(mid):
            end = mid
        else:
            start = mid+1
    return start

print(solve())
