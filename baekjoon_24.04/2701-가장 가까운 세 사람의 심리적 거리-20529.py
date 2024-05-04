import sys

input = sys.stdin.readline

t = int(input())


def diff(p1, p2):
    ret = 0
    for i in range(4):
        if p1[i] != p2[i]:
            ret += 1
    return ret


def testcase():
    n = int(input())
    arr = input().split()
    if n >= 33:
        return 0
    ret = 987654321
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                r1 = diff(arr[i], arr[j])
                r2 = diff(arr[j], arr[k])
                r3 = diff(arr[i], arr[k])
                ret = min(ret, r1 + r2 + r3)
    return ret


for i in range(t):
    print(testcase())
