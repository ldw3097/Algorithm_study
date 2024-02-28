n = int(input())
term = [0,1]
for i in range(2, 20):
    term.append(term[-1]*i)

def getperm(k):
    k -= 1
    arr = [i for i in range(1,n+1)]
    for i in range(n-1, 0, -1):
        divnum = term[i]
        d = 0
        if k//divnum >= 1:
            d, k = divmod(k, divnum)
        parret = arr[d]
        print(parret, end=" ")
        arr.remove(parret)
    print(arr[0])

def getk(inp):
    k = 1
    arr = [i for i in range(1,n+1)]
    for i in range(n):
        pos = arr.index(inp[i])
        k += term[n-i-1] * pos
        arr.remove(inp[i])
    print(k)

inp = tuple(map(int, input().split()))
if inp[0] == 1:
    getperm(inp[1])
else:
    getk(inp[1:])
