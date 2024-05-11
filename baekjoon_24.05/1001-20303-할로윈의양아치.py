import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())
candies = list(map(int, input().split()))
roots = [i for i in range(n)]
kids = [1 for i in range(n)]


def find(a):
    if roots[a] == a:
        return a
    else:
        root = find(roots[a])
        roots[a] = root
        return root


def union(a, b):
    aroot = find(a)
    broot = find(b)
    roots[broot] = aroot
    kids[aroot] += kids[broot]
    candies[aroot] += candies[broot]


for _ in range(m):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    if find(a) != find(b):
        union(a, b)

candyagg = []
dp = [0 for _ in range(k)]


# 1d 냅색
def knapsack(i):
    kid = kids[i]
    candy = candies[i]
    # 거꾸로 돔으로써 중복 적용 방지
    for i in range(k - 1, kid - 1, -1):
        dp[i] = max(dp[i], dp[i - kid] + candy)


for i in range(n):
    if roots[i] == i:
        knapsack(i)

print(max(dp))
