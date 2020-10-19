t = input()
while t > 0 :
	t -= 1
	n , k = map(int,raw_input().split())
	a = map(int,raw_input().split())
	# print(a)
	ans = 0
	for x in a:
		if x > k:
			ans += x-k
	print(ans)

# 3
# 5 4
# 10 2 3 4 5
# 7 15
# 1 2 3 4 5 6 7
# 5 5
# 10 9 8 7 6
