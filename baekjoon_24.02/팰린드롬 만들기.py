s = input()
alphas = {}
for c in s:
    alphas.setdefault(c,0)
    alphas[c] += 1

def solve():
    oddone = []
    for k,v in alphas.items():
        if v%2 == 1:
            if oddone != []:
                print("I'm Sorry Hansoo")
                return
            oddone = [k]
    fronthalf = []
    for k in sorted(alphas.keys()) :
        v = alphas[k]
        fronthalf.extend([k]*(v//2))
    ret = fronthalf + oddone + list(reversed(fronthalf))
    print("".join(ret))
    return

solve()


