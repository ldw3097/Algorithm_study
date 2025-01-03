

msg = input()
key = input()

def findyx(alp, pf):
    for i in range(5):
        for j in range(5):
            if pf[i][j] == alp:
                return (i,j)

def solve():
    playfair = [[] for _ in range(5)]
    i = 0
    added = set()
    for c in key:
        if c not in added:
            added.add(c)
            playfair[i//5].append(c)
            i += 1

    for c in [chr(i) for i in range(ord('A'), ord('Z')+1)]:
        if c not in added and c != 'J':
            playfair[i//5].append(c)
            i += 1
    
    splitted = []
    i = 0
    while i < len(msg):
        if i == len(msg) -1:
            splitted.append((msg[i], 'X'))
            break
        if msg[i] == msg[i+1]:
            if msg[i] == 'X':
                splitted.append((msg[i], 'Q'))
            else:
                splitted.append((msg[i], 'X'))
            i += 1
        else:
            splitted.append((msg[i], msg[i+1]))
            i += 2
    
    ret = []
    for splel in splitted:
        yx1 = findyx(splel[0], playfair)
        yx2 = findyx(splel[1], playfair)
        if yx1[0] == yx2[0]:
            y1 = y2 = yx1[0]
            x1 = (yx1[1]+1)%5
            x2 = (yx2[1]+1)%5
        elif yx1[1] == yx2[1]:
            y1 = (yx1[0]+1)%5
            y2 = (yx2[0]+1)%5
            x1=x2=yx1[1]
        else:
            y1 = yx1[0]
            y2 = yx2[0]
            x1 = yx2[1]
            x2 = yx1[1]

        ret.extend([playfair[y1][x1], playfair[y2][x2]])

    print(''.join(ret))    


solve()