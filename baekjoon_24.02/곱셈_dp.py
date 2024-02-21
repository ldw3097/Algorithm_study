
a,b,c = map(int,input().split())
dp = {}

def multi (a,n):
  if n == 1:
      return a%c
  else:
      if n in dp:
          return dp[n]
      tmp = multi(a,n//2)
      if n %2 ==0:
          ret = (tmp * tmp) % c
          dp[n] = ret
          return ret
      else:
          ret = (tmp  * tmp *a) %c
          dp[n] = ret
          return ret
          
print(multi(a,b))