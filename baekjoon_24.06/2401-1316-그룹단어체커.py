n = int(input())


def isgroupword(word):
    wordset = set()
    prevword = ""
    for c in word:
        if c != prevword and c in wordset:
            return False
        wordset.add(c)
        prevword = c
    return True


ret = 0
for _ in range(n):
    ret += isgroupword(input())

print(ret)
