#Amit(18BCS2059)
#recursive function of factorial
def fact(n):
	if n == 1:
		return 1
	return n*fact(n-1)

#iterative function of factorial
def factitr(n):
	a = 1
	for i in range(n):
		a *= (i+1)
	return a

print('Factorial of 8 using iterative function:')
n = factitr(8)
print(n)
print('Factorial of 10 using recursive function:')
n = factitr(10)
print(n)
