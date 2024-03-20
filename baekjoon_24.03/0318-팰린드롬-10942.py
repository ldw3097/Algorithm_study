import sys
from collections import *
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
m = int(input())

pals = defaultdict(set)

def getpal1(pos):
    i = 0
    while pos-i >= 0 and pos+i < n:
        if arr[pos-i] != arr[pos+i]:
            break
        pals[pos-i].add(pos+i)
        i += 1
    
def getpal2(pos):
    i = 0
    while pos-i >= 0 and pos+i+1 < n:
        if arr[pos-i] != arr[pos+i+1]:
            break
        pals[pos-i].add(pos+i+1)
        i += 1

for i in range(n):
    getpal1(i)
    getpal2(i)

for i in range(m):
    a,b = map(int,input().split())
    if b-1 in pals[a-1]:
        print(1)
    else:
        print(0)

