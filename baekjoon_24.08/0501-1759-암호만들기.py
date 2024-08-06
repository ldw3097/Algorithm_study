from itertools import *

l, c = map(int, input().split())
alp = input().split()
alp.sort()

vowel = []
consonant = []

for char in alp:
    if char in ['a', 'e', 'i', 'o', 'u']:
        vowel.append(char)
    else:
        consonant.append(char)

ret = []
for vnum in range(1, min(l-2, len(vowel))+1):
    cnum = l - vnum
    vs = list(combinations(vowel, vnum))
    cs = list(combinations(consonant, cnum))
    for vsc in vs:
        for csc in cs:
            parret = []
            parret.extend(vsc)
            parret.extend(csc)
            parret.sort()
            ret.append("".join(parret))
ret.sort()
for retel in ret:
    print(retel)