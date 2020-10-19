import math
t = int(input())
while t > 0:
	n = int(input())
	ans = 0
	bot = math.floor(math.log2(n))
	top = math.ceil(math.log2(n))
	if n == 1:
		print(0)
	elif top == bot:
		print(0)
	elif n&1:
		print(n//2)
	else:
		while ~n&1:
			n = n >> 1
		print(n//2)