print("AMIT KUMAR")
print("18BCS2059")
g = 9
def check():
    global x
    x  = 67
    v = 77
    print(x, "is global")
    print(g, "is also global")
    print(v, "is local")

check()
