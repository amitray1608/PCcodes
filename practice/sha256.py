import hashlib

hs = hashlib.sha256()

for i in range(1, 5):
    x = input("Enter a string:")
    hs.update(x.encode('utf-8'))
    print(hs.hexdigest())

