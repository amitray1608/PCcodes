def string_multi(first, second): 
	len1 = len(first) 
	len2 = len(second) 
	if len1 == 0 or len2 == 0: 
		return "0"
	ans = [0] * (len1 + len2) 
	itr1 = 0
	itr2 = 0
	for i in range(len1 - 1, -1, -1): 
		carry = 0
		n1 = ord(first[i]) - 48
		itr2 = 0
		for j in range(len2 - 1, -1, -1): 
			n2 = ord(second[j]) - 48
			summ = n1 * n2 + ans[itr1 + itr2] + carry 
			carry = summ // 10
			ans[itr1 + itr2] = summ % 10
			itr2 += 1
		if (carry > 0): 
			ans[itr1 + itr2] += carry 
		itr1 += 1
	i = len(ans) - 1
	while (i >= 0 and ans[i] == 0): 
		i -= 1
	if (i == -1): 
		return "0"
	s = "" 
	while (i >= 0): 
		s += chr(ans[i] + 48) 
		i -= 1
	return s
	

def solution(xs):
	n = len(xs)
	n-=1
	count = 0
	pos = 0
	z = 0
	xs.sort()
	for i in xs:
		if(i < 0):
			count += 1
		if(i == 0):
			z += 1
		if(i > 0):
			pos += 1
	ans = '1'
	if n == 0:
		return str(xs[n])
	if z == n+1:
		return "0"
	if z == len(xs)-1 and count == 1:
		return "0"
	while(n >= 0 and xs[n] > 0):
		ans = string_multi(ans, str(xs[n]))
		n-=1
		# print(ans)
	if(count&1):
		count -= 1
	i = 0
	# print('neg')
	# print(count)
	while(i < count):
		ans = string_multi(ans, str(abs(xs[i])))
		i += 1
		# print(ans)
	return ans
		
print(solution([0, 0, 0, -1]))
print("end")
print(solution([2, -2, 2, 2, 0]))
print("end")
print(solution([-2, -3	, 4, -5]))
print("end")

1 3 6 10
2 5 9
4 8
7
