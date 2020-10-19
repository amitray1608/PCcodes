t = input(int)
# print(type(t))
while t > 0 :
	t -= 1
	s = raw_input()
	n = len(s)
	# print(n)
	ans = 0
	i = 0
	# print(type(s))
	while i  < (n-1):
		# print(s[i], s[i+1])
		if (s[i+1] == 'x' and s[i] == 'y' ) or (s[i] == 'x' and s[i+1] == 'y' ) :
			ans += 1
			i += 1
		i += 1
	print(ans)

