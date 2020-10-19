#let's learn python
for i in range(int(input())):
    n, m = map(int, input().split())
    flag = False
    a = []
    for i in range(n):
        a.append([[int(x) for x in input().split()] for i in range(2)])
    for i in range(n):
            flag |= a[i][0][1] == a[i][1][0]
    flag &= (~m&1)
    print('YES' if flag else 'NO')

