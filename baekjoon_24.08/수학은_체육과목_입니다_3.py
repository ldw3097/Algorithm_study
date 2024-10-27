c = input()

def finalpos(i):
    num = int(c[0:i])
    pos = i
    while pos < len(c):
        num += 1
        i = len(str(num))
        newnum = int(c[pos:pos+i])
        if num != newnum:
            return -1
        pos += i
    return num
        

def solve():
    for i in range(1, 2890):
        ret = finalpos(i)
        if ret != -1:
            print(f'{c[0:i]} {ret}')
            return
        
        
solve()