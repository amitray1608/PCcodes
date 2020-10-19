t = int(input())
while t > 0:
	t -= 1
	n = input()
	a = [int(i) for i in input().split()]
	# a = map(int, input().strip(), split())
	h = 0
	f = 0
	ans = 0
	flag = True
	for i in a:
		if i == 5:
			h += 1
		elif i == 10:
			f += 1
			if h > 0:
				h -=1
			else:
				flag = False
				break
		else:
			if(f > 0):
				f -= 1
			elif h > 1:
				h -=1
			else:
				flag = False
				break
	if flag:
		print("YES")
	else:
		print("NO")

