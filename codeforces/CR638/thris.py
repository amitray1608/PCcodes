from queue import Queue 
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
vis = [[0]*20]*20
def go(x, y, h, w):
	if x >= 0 and x < h and y >= 0 and y < w-1:
		return True
	return False

def solve(x, y, used, arr, h, w):
	cost = [[100]*w]*h
	cost[x][y] = 1
	q = Queue()
	q.put([x, y, used])
	vis[x][y] = 1
	while q.empty() == False:
		l = q.get()
		print(l)
		for i in range(0, 4):
			xx = l[0]+dx[i]
			yy = l[1]+dy[i]
			if(go(xx, yy, h, w) and vis[xx][yy] == 0):
				vis[xx][yy] = 1
				cost[xx][yy] = min(cost[xx][yy], cost[l[0]][l[1]]+1)
				if arr[xx][yy] == 0:
					q.put([xx, yy, l[2]])
					print("ok")
				elif l[2] == 1:
					print("thik")
					q.put([xx, yy, 0])
	for i in cost:
		for j in i:
			print(j, end = " ")
		print()
	return cost[h-1][w-1]
	
def solution(arr):
	h = len(arr)
	w = len(arr[0])
	mini = solve(0, 0, 1, arr, h, w)
	# for i in cost:
		# for j in i :
			# print(j, end = " ")
	return str(mini)
	
print(solution([[0, 0, 1, 0], [1, 0,1, 0], [0, 0, 0, 0], [0, 0, 1, 0]]))
print("end")
print(solution([[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]))
print("end")
print(solution([[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]))
print("end")
