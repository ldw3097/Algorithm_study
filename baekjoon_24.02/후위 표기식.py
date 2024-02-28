exp = input()
endpos = len(exp)
# 연산자 우선순위
op = {"+":1, "-":1, "*":2, "/":2}

# 연산자가 하나 들어왔을때 출력하는 함수
def doop(stk,out,o):
    while len(stk)>0 and op[stk[-1]] >= op[o]:
        out.append(stk.pop())
    stk.append(o)

pos = 0
# 중위표기식을 후위표기식으로 변환하는 함수
def solve():
    global pos
    stk = []
    out = []
    while pos < endpos and exp[pos] != ")":
        # 괄호가 시작될경우 재귀적으로 변환식을 찾음
        if exp[pos] == "(":
            pos += 1
            out.extend(solve())
        elif exp[pos] in op:
            doop(stk,out,exp[pos])
        else:
            out.append(exp[pos])
        pos += 1
    # 스택에 남은 연산자를 출력함
    while stk:
        out.append(stk.pop())
    return out

ret = solve()
print("".join(ret))
