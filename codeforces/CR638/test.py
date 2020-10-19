from collections import deque
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
def go(x, y, h, w):
	if x >= 0 and x < h and y >= 0 and y < w-1:
		return True
	return False

def solution(arr):
	h = len(arr)
	w = len(arr[0])
	mini = solve(0, 0, 1, cost, vis, arr, h, w);
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

