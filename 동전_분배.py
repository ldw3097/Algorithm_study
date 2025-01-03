

def tc():
    n = int(input())
    coins = []
    total = 0
    for _ in range(n):
        a,b = map(int, input().split())
        coins.append((a,b))
        total += a*b
    if total % 2 == 1:
        return 0
    halftotal = total // 2

    coins.sort(key=lambda x: x[1], reverse=True)
    coinset = {0}
    for a,b in coins:
        newcoins = set()
        for precoin in coinset:
            for i in range(1, b+1):
                newcoin = precoin + a*i
                if newcoin == halftotal:
                    return 1
                if newcoin > halftotal or newcoin in coinset:
                    break
                newcoins.add(newcoin)
        coinset |= newcoins
    return 0

def solve():
    for _ in range(3):
        ret = tc()
        print(ret)

solve()