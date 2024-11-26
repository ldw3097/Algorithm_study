inp = input()

def checkstk(stk):
    while len(stk) >= 4 and stk[-1] == 'P' and stk[-2] == 'A' and stk[-3] == 'P' and stk[-4] == 'P':
        for _ in range(3):
            stk.pop()
    

def solve():
    stk = []
    for c in inp:
        stk.append(c)
        checkstk(stk)
    if len(stk) == 1 and stk[0] == 'P':
        print('PPAP')
    else:
        print('NP')

solve()