from sys import stdin
input = stdin.readline

n, m, p = map(int, input().rstrip().split(' '))
a = [int(x) for x in input().rstrip().split(' ')]
b = [int(x) for x in input().rstrip().split(' ')]

def getA(index):
    return 0 if n <= index else a[index]

def getB(index):
    return 0 if m <= index else b[index]

def calcElement(index):
    sum = 0
    for i in range(0, index+1):
        sum += getA(i)*getB(index-i)
    return sum

result = -1
for i in range(0, n+m-1):
    element = calcElement(i)
    if element % p != 0:
        result = element % 1000000007
        break

print(result)