a, b, c =  map(int, input().split())
if c & 1:
    c = 3
else:
    c = 2
if a ** c == b ** c:
    print("=")
elif a ** c < b ** c:
    print("<")
else:
    print(">")
