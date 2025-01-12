

n, tae, p = map(int, input().split())
if n == 0:
    print(1)
    quit()
arr = list(map(int, input().split()))

arr.sort(reverse=True)
lindex = 0
rindex = n
for i in range(n):
    if arr[i] > tae:
        lindex = i+1
    if arr[i] < tae:
        rindex = i 
        break

if rindex >= p:
    print(-1)
    quit()
print(lindex+1)

