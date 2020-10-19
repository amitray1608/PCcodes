import math
n = int(input())
h = 0
c = 0
e = 0.0
x = list(map(int,input().split()))
for i in range(0, n):
    h += abs(x[i])
    e += (x[i] * x[i])
    c = max(c, abs(x[i]))
print(h)
print(math.sqrt(e))
print(c)
