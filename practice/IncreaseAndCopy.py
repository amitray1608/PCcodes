#let's learn python
import math

t  = int(input())
for i in range(t):
    n = int(input())
    ans = math.ceil(2*math.sqrt(n)) - 2
    print(ans)
