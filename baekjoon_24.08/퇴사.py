n = int(input())
tp = []
for _ in range(n):
    tp.append(list(map(int, input().split())))
    
profit = [0]*(n+1)

    
def solve():
    for i in range(n):
        t, p = tp[i]
        nextprofit = profit[i]+p
        receiveday = i+t
        for j in range(receiveday, n+1):
            if profit[j] >= nextprofit:
                break
            profit[j] = nextprofit
            
    print(profit[n])
    
solve()