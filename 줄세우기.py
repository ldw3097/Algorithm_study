

def tc():
    tcnum, *stu = map(int, input().split())
    tmp = []
    ret = 0
    for student in stu:
        for tstudent in tmp:
            if student < tstudent:
                ret += 1
        tmp.append(student)
    print(f'{tcnum} {ret}')

p = int(input())
for _ in range(p):
    tc()