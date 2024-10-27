import sys
input = sys.stdin.readline

ret = 0
while True:
    inp = input()
    if inp == "":
        break
    else:
        ret += int(inp)
        
print(ret)