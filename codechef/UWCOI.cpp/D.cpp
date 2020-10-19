#wap to find max min mean median mode of a list of numbers using user defined functions.
#MINI
def mini(l, n):
    x = l[0]
    for i in range(n):
        if x > l[i]:
            x = l[i]
    return x
#MAXI
def maxi(l, n):
    x = l[0]
    for i in range(n):
        if x < l[i]:
            x = l[i]
    return x
#MEAN
def mean(l, n):
    x = 0
    for i in range(n):
        x += l[i]
    return x/n
#MEDIAN
def median(l, n):
    l.sort()
    if n&1:
        return l[n//2]
    else:
        return (l[n//2]+l[n//2-1] / 2)
#MODE
def mode(array, n):
    most = max(list(map(array.count, array)))
    return list(set(filter(lambda x: array.count(x) == most, array)))

l = [1, 2, 3, 4, 5, 2]
n = 6
print('Minimum element : ')
m = mini(l, n)
print(m)
print('Maximum element : ')
m = maxi(l, n)
print(m)
print('Mean of the list : ')
m = mean(l, n)
print(m)
print('Median of the list : ')
m = median(l, n);
print(m)
print('Mode of the list : ')
m = mode(l, n);
print(m)
