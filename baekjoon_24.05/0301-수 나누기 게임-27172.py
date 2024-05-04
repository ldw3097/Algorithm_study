# n = int(input())
# arr = list(map(int, input().split()))

# ret = [0 for _ in range(len(arr))]

# for i in range(len(arr) - 1):
#     for j in range(i, len(arr)):
#         if arr[i] % arr[j] == 0:
#             ret[i] -= 1
#             ret[j] += 1
#         elif arr[j] % arr[i] == 0:
#             ret[i] += 1
#             ret[j] -= 1


# for i in ret:
#     print(i, end=" ")


n = int(input())
arr = list(map(int, input().split()))

s = set(arr)
m = max(arr)

ret = [0 for _ in range(m + 1)]
for i in arr:
    for j in range(i * 2, m + 1, i):
        if j in s:
            ret[i] += 1
            ret[j] -= 1

for i in arr:
    print(ret[i], end=" ")
