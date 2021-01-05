# Uses python3
import sys

def lcm(a, b):
    return (a // gcd(a, b)) * b

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


if __name__ == '__main__':
    input = sys.stdin.read()
    a, b = map(int, input.split())
    print(lcm(a, b))

