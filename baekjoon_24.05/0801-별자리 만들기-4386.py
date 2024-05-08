import heapq

n = int(input())
stars = []
for i in range(n):
    x, y = map(float, input().split())
    stars.append((x, y))


def calcdist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


dists = [[] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        dists[i].append((calcdist(*stars[i], *stars[j]), j))

ret = 0
connected = {0}
edges = dists[0]
heapq.heapify(edges)


while len(connected) < n:

    dist, star = heapq.heappop(edges)
    if star in connected:
        continue
    connected.add(star)
    ret += dist
    edges.extend(dists[star])
    heapq.heapify(edges)

print("{:.2f}".format(ret))
