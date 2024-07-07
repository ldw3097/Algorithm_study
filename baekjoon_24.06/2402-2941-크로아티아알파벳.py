inp = input()

alpha = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
ret = len(inp)
for a in alpha:
    ret -= inp.count(a)
print(ret)
