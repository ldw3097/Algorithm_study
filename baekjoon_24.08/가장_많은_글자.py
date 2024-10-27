from collections import Counter
import sys
input = sys.stdin.readline

cnt = Counter()
while True:
    inp = input()
    if inp == "":
        break
    cnt += Counter(inp)
if " " in cnt:
    cnt.pop(" ")
cnt.pop('\n')
max_cnt = max(cnt.values())
for c in sorted(cnt):
    if cnt[c] == max_cnt:
        print(c, end="")