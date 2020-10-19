t = int(input())
while t > 0:
	t -= 1
	n = int(input())
	count = 0
	l = []
	z = 1
	for i in range(n):
		x = []
		for j in range(n):
			count += 1
			x.append(count)
		if z:
			l.append(x)
		else:
			x.reverse()
			l.append(x)
		z ^= 1
	print(l)
