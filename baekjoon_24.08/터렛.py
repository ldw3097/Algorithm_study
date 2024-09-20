t = int(input())

def tc():
    x1,y1,r1,x2,y2,r2 = map(int, input().split())
    if r1 < r2:
        x1,y1,r1,x2,y2,r2 = x2,y2,r2,x1,y1,r1
    dist = (abs(x1-x2)**2 + abs(y1-y2)**2) ** 0.5
    rdist = r1+r2
    
    if (x1,y1) == (x2,y2):
        if r1 != r2:
            print(0)
        else:
            print(-1)
    elif dist < r1:
        if dist+r2 < r1:
            print(0)
        elif dist+r2 == r1:
            print(1)
        else:
            print(2)
    else:
        if dist == rdist:
            print(1)
        elif dist > rdist:
            print(0)
        else:
            print(2)
            
for _ in range(t):
    tc()