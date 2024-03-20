n = int(input())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))

ret = 0
for i in range(n):
    j = (i+1)%n
    ret = ret + arr[i][0]*arr[j][1] - arr[i][1]*arr[j][0]

ret = abs(ret)/2
print(ret)