n = int(input())

sieve = [True] * (n + 1)
sieve[0] = False
sieve[1] = False
prime = []
for i in range(2, n + 1):
    if sieve[i]:
        prime.append(i)
        for j in range(i * 2, n + 1, i):
            sieve[j] = False


def testcase():
    if n == 1:
        return 0
    tail = 0
    head = 0
    ret = 0
    current = 2

    while True:
        if current < n:
            head += 1
            if head >= len(prime):
                break
            current += prime[head]
        else:
            if current == n:
                ret += 1
            current -= prime[tail]
            tail += 1
    return ret


print(testcase())
