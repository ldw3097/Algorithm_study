

n = int(input())
tests = []
for _ in range(3):
    tests.append(list(map(int, input().split())))

def getgrade(test):
    withord = [(test[i], i) for i in range(n)]
    withord.sort(reverse=True)
    ret = [-1]*n
    prev = -1
    previ = -1
    for i, (score, ord) in enumerate(withord):
        if score == prev:
            ret[ord] = previ
        else:
            ret[ord] = i+1
            prev = score
            previ = i+1
    return ret

def printgrade(grades):
    for grade in grades:
        print(grade, end=' ')
    print()

def solve():
    for test in tests:
        parret = getgrade(test)
        printgrade(parret)

    total = [tests[0][i] + tests[1][i] + tests[2][i] for i in range(n)]
    parret = getgrade(total)
    printgrade(parret)

solve()