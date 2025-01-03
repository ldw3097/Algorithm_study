n = int(input())
stt = list(map(int, input()))
end = list(map(int, input()))
inf = 9876543210

def getseq(seq):
    for i in range(1, n-1):
        seq[i+1] = (stt[i]^end[i]) ^ (seq[i-1]^seq[i])
    if seq[n-2] ^ seq[n-1] != stt[n-1] ^ end[n-1]:
        return inf
    return sum(seq)

def solve():
    if stt[0] ^ end[0] == 0:
        occ1 = [0] * n
        occ1[0] = occ1[1] = 1
        occ2 = [0] * n
    else:
        occ1 = [0] * n
        occ2 = [0] * n
        occ1[0] = occ2[1] = 1

    ret1 = getseq(occ1)
    ret2 = getseq(occ2)
    ret = min(ret1, ret2)
    if ret == inf:
        return -1
    return ret

print(solve())