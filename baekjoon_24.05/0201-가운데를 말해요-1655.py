import sys

input = sys.stdin.readline
import heapq

n = int(input())
first = int(input())
left = [-first]
right = [first]
print(first)


def stabilize(left, right):
    if len(right) >= len(left) + 2:
        heapq.heappop(right)
        heapq.heappush(left, -right[0])
    elif len(left) > len(right):
        heapq.heappop(left)
        heapq.heappush(right, -left[0])


for i in range(n - 1):
    inp = int(input())
    if inp >= right[0]:
        heapq.heappush(right, inp)
    else:
        heapq.heappush(left, -inp)
    stabilize(left, right)
    print(right[0])
