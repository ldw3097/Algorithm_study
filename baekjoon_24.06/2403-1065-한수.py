n = int(input())


def ishansu(i):
    diff = -999
    last = -999
    while i > 0:
        i, leftover = divmod(i, 10)
        if last == -999:
            last = leftover
            continue
        if diff == -999:
            diff = last - leftover
            last = leftover
            continue
        if (last - leftover) != diff:
            return False
        last = leftover
    return True


ret = 0
for i in range(1, n + 1):
    ret += ishansu(i)
print(ret)
