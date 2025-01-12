

h, w, n, m = map(int, input().split())
a = h // (n+1) + (1 if (h % (n+1)) else 0)
b = w // (m+1) + (1 if (w % (m+1)) else 0)
print(a*b)