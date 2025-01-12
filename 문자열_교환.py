
inp = list(input())
inplen = len(inp)
acnt = inp.count('a')
currenta = inp[:acnt].count('a')
ret = acnt - currenta

for i in range(1, inplen):
    if inp[i-1] == 'a':
        currenta -= 1
    if inp[(i+acnt-1)%inplen] == 'a':
        currenta += 1
    ret = min(ret, acnt - currenta)

print(ret)