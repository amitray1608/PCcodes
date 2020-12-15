def solve():
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(input())

    dp = []
    for i in range(n):
        dp.append([])
        for j in range(m):
            dp[i].append((1 if a[i][j] == '*' else 0) if j == 0 else dp[i][j - 1] + (1 if a[i][j] == '*' else 0))

    count = 0
    for x in range(n):
        for y in range(m):
            if a[x][y] == '.':
                continue
            for level in range(min(n - x, m - y, y + 1)):
                if dp[x + level][y + level] - (0 if y - level - 1 < 0 else dp[x + level][y - level - 1]) != level * 2 + 1:
                        break;

                count += 1

    print(count)

test = int(input())
while(test > 0):
    solve()
    test = test - 1


