n, l = map(int, input().split())
inp = []
for _ in range(n):
    inp.append(list(map(int, input().split())))


def iscrossable(arr):
    occupied = set()
    def checkandoccupy(i, dir):
        val = arr[i]
        for j in range(i, i + l * dir, dir):
            if j<0 or j>=n or arr[j] != val or j in occupied:
                return False
            occupied.add(j)
        return True

    for i in range(n-1):
        if arr[i] != arr[i+1]:
            if abs(arr[i]-arr[i+1]) >= 2 :
                return 0
            if arr[i]  == arr[i+1]+1:
                if checkandoccupy(i+1, 1) == False:
                    return False
            elif arr[i]+1 == arr[i+1]:
                if checkandoccupy(i,-1) == False:
                    return False

    return True

ret = 0
for i in range(n):
    ret += iscrossable(inp[i])

for i in range(n):
    arr = [inp[j][i] for j in range(n)]
    ret += iscrossable(arr)

print(ret)
