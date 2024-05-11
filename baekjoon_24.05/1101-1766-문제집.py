import sys
import heapq

input = sys.stdin.readline
sys.setrecursionlimit(10**5)

n, m = map(int, input().split())
conn = {}
inbound = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    conn.setdefault(a, [])
    conn[a].append(b)
    inbound[b] += 1

hq = []
for i in range(1, n + 1):
    if inbound[i] == 0:
        heapq.heappush(hq, i)

ret = []
while hq:
    a = heapq.heappop(hq)
    ret.append(a)
    if a in conn:
        for b in conn[a]:
            inbound[b] -= 1
            if inbound[b] == 0:
                heapq.heappush(hq, b)

for i in ret:
    print(i, end=" ")


# ret = []
# visited = set()


# def traverse(i):
#     if i in visited:
#         return
#     visited.add(i)
#     if i in conn:
#         for j in sorted(conn[i], reverse=True):
#             traverse(j)
#     ret.append(i)


# for i in range(n, 0, -1):
#     traverse(i)

# ret.reverse()
# for i in ret:
#     print(i, end=" ")
