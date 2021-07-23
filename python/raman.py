import pandas as pd

filename = 'student.csv'

#TASK 2 : CSV file imported
df = pd.read_csv(filename)
print("\n\nActual data in the CSV file: \n")
print(df.to_string())

#TASK 3 : To print first 5 rows of the dataframe
firstFive = df.head(5)
print("\nFirst 5 rows : \n")
print(firstFive)

#TASK 3: To print last 5 rows of the dataframe
lastFive = df.tail(5)
print("\n\nLast 5 rows : \n")
print(lastFive)

#TASK 4: To print the row whose marks > 78
onMarks = df.query('marks > 78')
print("\n\nRows with marks > 78 :\n")
print(onMarks)

#TASK 5: Create a DF with sorted records on column marks
sortedDf = df.sort_values(by = 'marks')
print("\n\nDF sorted on the basis of marks: \n")
print(sortedDf)

#TASK 6: Print the records 4, 5, 6, 7 with column name and marks
range = df[3:7]
print("\n\nNew DF name and marks in range 4 .. 7: \n")
print(range[['name', 'marks']])
