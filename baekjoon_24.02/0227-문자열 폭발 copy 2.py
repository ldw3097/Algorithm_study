inp = input()
bomb = list(input())
bomblen = len(bomb)

stk = [""]*len(inp)
p = 0
for v in inp:
    stk[p] = v
    p += 1
    while stk[p-bomblen:p] == bomb:
        p -= bomblen


if p == 0:
    print("FRULA")
else:
    print("".join(stk[:p]))