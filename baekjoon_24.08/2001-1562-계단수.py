
divider = 1000000000
dp = {}

def solve():
    n = int(input())
    ret = 0
    for i in range(1, 10):
        ret = (ret + num_of_case(i, n, 0)) % divider
    print(ret)

def num_of_case (target, remain, bitmask):
    if (target, remain, bitmask) in dp:
        return dp[(target, remain, bitmask)]
    newbitmask = bitmask | (1<<target)
    hole = get_hole(newbitmask)
    newremain = remain -1
    if newremain < hole:
        dp[(target, remain, bitmask)] = 0
        return 0
    if newremain == 0:
        return 1
    ret = 0
    if target != 9:
        ret += num_of_case(target+1, newremain, newbitmask)
    if target != 0:
        ret += num_of_case(target-1, newremain, newbitmask)
    ret %= divider
    dp[(target, remain, bitmask)] = ret
    return ret


def get_hole(bitmask):
    ret = 0
    for i in range(10):
        if bitmask & (1<<i) == 0:
            ret += 1
    return ret

solve()