n = int(input())
arrinp = []
for _ in range(n):
    arrinp.append(list(map(int, input().split())))


def ypush(right, arr):
    newarr = [[0] * n for _ in range(n)]
    if right:
        direction = (0, n, 1)
    else:
        direction = (n - 1, -1, -1)

    for i in range(n):
        idx = direction[0]
        for j in range(*direction):
            if arr[i][j] == 0:
                continue
            elif newarr[i][idx] == 0:
                newarr[i][idx] = arr[i][j]
            elif arr[i][j] == newarr[i][idx]:
                newarr[i][idx] += arr[i][j]
                idx += direction[2]
            else:
                idx += direction[2]
                newarr[i][idx] = arr[i][j]
    return newarr


def xpush(right, arr):
    newarr = [[0] * n for _ in range(n)]
    if right:
        direction = (0, n, 1)
    else:
        direction = (n - 1, -1, -1)

    for i in range(n):
        idx = direction[0]
        for j in range(*direction):
            if arr[j][i] == 0:
                continue
            elif newarr[idx][i] == 0:
                newarr[idx][i] = arr[j][i]
            elif arr[j][i] == newarr[idx][i]:
                newarr[idx][i] += arr[j][i]
                idx += direction[2]
            else:
                idx += direction[2]
                newarr[idx][i] = arr[j][i]
    return newarr


ret = 0


def dfs(remain, array):
    global ret
    if remain == 0:
        parret = max(map(max, array))
        ret = max(ret, parret)
        return
    remain -= 1
    dfs(remain, ypush(True, array))
    dfs(remain, ypush(False, array))
    dfs(remain, xpush(True, array))
    dfs(remain, xpush(False, array))


dfs(5, arrinp)
print(ret)
