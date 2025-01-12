n = int(input())
ch = []
for _ in range(n):
    ch.append(input())

arrow = 0
def movetarget(target, endpos):
    targetpos = ch.index(target)
    if targetpos == endpos:
        return
    global arrow
    firstact = '1' if arrow < targetpos else '2'
    print(firstact*abs(targetpos-arrow), end='')
    arrow = targetpos

    secondact = '3' if arrow < endpos else '4'
    direction = 1 if endpos > arrow else -1
    for i in range(arrow, endpos, direction):
        print(secondact, end= '')
        ch[i], ch[i+direction] = ch[i+direction], ch[i]
        arrow += direction

movetarget('KBS1', 0)
movetarget('KBS2', 1)
    