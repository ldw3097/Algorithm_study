import heapq
n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))

heapq.heapify(arr)
ret = 0
while len(arr) >= 2:
    a = heapq.heappop(arr)
    b = heapq.heappop(arr)
    ret += a+b
    heapq.heappush(arr, a+b)

print(ret)