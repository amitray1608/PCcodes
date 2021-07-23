import numpy as np
str1 = "this is string example....wow!!!"
str2 = "exam"
print(str1.find(str2))
print(str1.find(str2, 10))
print(str1.find(str2, 40))

Ar = [1, 3, 5, 7, 11, 13, 15, 20, 21]
print(Ar[1:8:2])

import numpy as np
print(np.random.rand(10, 5))

import pandas as pd
data1 = {"id" : [10,20,30,40],
        "Name" :["Amit","Amita","raghav", "Amisha"],
    "Subject":['maths','science', 'history', 'English'], 
    "Marks":[60,70,50,89], 
    "Sex":["M","F","M", "F"]
    }
df = pd.DataFrame(data1)
print(df)


def reverseList(A, start, end):
    while start < end:
        A[start], A[end] = A[end], A[start]
        start += 1
        end -= 1

print("Original list is")
A = [1, 2, 3, 4, 5, 6]
print(A)
reverseList(A, 0, 5)
print("Reversed list is")
print(A)

