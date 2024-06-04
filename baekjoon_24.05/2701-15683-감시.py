from copy import deepcopy
import sys

sys.setrecursionlimit(10**5)

n, m = map(int, input().split())
office = []
for _ in range(n):
    office.append(list(map(int, input().split())))

cctvs = []
fives = []
for i in range(n):
    for j in range(m):
        if office[i][j] in (1, 2, 3, 4):
            cctvs.append((i, j))
        if office[i][j] == 5:
            fives.append((i, j))


def nextplace(y, x, dir):
    if dir == 1:
        while 0 <= y < n:
            yield (y, x)
            y -= 1
    if dir == 2:
        while 0 <= x < m:
            yield (y, x)
            x += 1
    if dir == 3:
        while 0 <= y < n:
            yield (y, x)
            y += 1
    if dir == 4:
        while 0 <= x < m:
            yield (y, x)
            x -= 1


def fill(y, x, dirs, office_state):
    for dir in dirs:
        for ny, nx in nextplace(y, x, dir):
            if office_state[ny][nx] == 6:
                break
            if office_state[ny][nx] == 0:
                office_state[ny][nx] = -1


dirset = {
    1: ((1,), (2,), (3,), (4,)),
    2: ((1, 3), (2, 4)),
    3: ((1, 2), (2, 3), (3, 4), (4, 1)),
    4: ((1, 2, 3), (2, 3, 4), (3, 4, 1), (4, 1, 2)),
}


for i, j in fives:
    fill(i, j, (1, 2, 3, 4), office)


def count_zeros(office_state):
    ret = 0
    for i in range(n):
        for j in range(m):
            if office_state[i][j] == 0:
                ret += 1
    return ret


cctvs_lim = len(cctvs)


def do_case(office_state, cctv_num):
    if cctv_num == cctvs_lim:
        return count_zeros(office_state)
    y, x = cctvs[cctv_num]
    cctv_type = office[y][x]
    ret = 987654321
    for dirs in dirset[cctv_type]:
        new_office_state = deepcopy(office_state)
        fill(y, x, dirs, new_office_state)
        ret = min(ret, do_case(new_office_state, cctv_num + 1))

    return ret


ret = do_case(office, 0)
print(ret)
