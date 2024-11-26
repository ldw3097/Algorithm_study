
import sys
input = sys.stdin.readline
#sys.stdin = open("input.txt", "r")

T = int(input())

def solve():
    arr = list(map(int, input().split()))
    ret = 0
    for i in arr:
        if i%2 == 1:
            ret += i
    return ret
               



# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    ret = solve()
    print(f'#{test_case} {ret}')
