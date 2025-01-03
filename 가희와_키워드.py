import sys
input = sys.stdin.readline

n,m = map(int, input().split())
words = set()

for _ in range(n):
    words.add(input().strip())

for _ in range(m):
    inp = set(input().strip().split(','))
    words -= inp
    print(len(words))

    