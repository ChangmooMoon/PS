a = [1,2,3,4,5,6,7,8,9]
print(a[1:4])

a = [i for i in range(10)]
print(a)

a = [i for i in range(20) if i % 2 ==1]
print(a)

n = 4
m = 3
a = [[0] * m for _ in range(n)]
print(a)

summary = 0
for i in range(1,10):
  summary += i
print(summary)

for _ in range(5):
  print("hi")

a = [1,4,3]
a.append(2)
a.sort()
a.sort(reverse = True)
a.reverse()

print(a)
a.insert(2,'x') # index, element
print(a)
print("3의 갯수",a.count(3))
a.remove(1)
print("값이 1인 데이터 삭제:", a)

a = [1,2,3,4,5,5,5]
remove_set = {3,5}
result = [i for i in a if i not in remove_set]
print(result)

a = (1,2,3,4,5,6,7,8,9)
print(a[1:4])

data = dict()
data['hi'] = 'morning'
data['hello'] = 'friend'
data['nihao'] = 'chinese'
print(data)
print(data.keys())
print(data.values())
print(type(data))
print(type(data.keys()))
print(type(data.values()))

data = set([1,2,3,4,5,5,5])
print(data)
data = {1,2,3,4,5,5,5,5}
print(data)

data.add(4)
data.update([5,6])
data.remove(3)
print(data)

i = 1
result = 0

while i <=9:
  if i%2 == 1:
    result += i
  i+= 1
print(result)
        
array = [9,8,7,6,5]
for x in array:
  print(x)

a = 10
def func():
  global a
  a += 1
  print(a)

func()

def operator(a,b):
  add = a+b
  subtract = a-b
  multiply = a*b
  divide = a/b
  return add, subtract, multiply, divide

a,b,c,d = operator(7,3)
print(a,b,c,d)

print((lambda a, b: a*a*b)(3,7))

array = [('홍길동', 50), ('이순신', 32), ('하',74)]
def my_key(x):
  return x[1]

print(sorted(array, key=my_key))
print(sorted(array, key=lambda x: x[1]))

list1 = [1,2,3,4,5]
list2 = [5,6,7,8,9]
result = map(lambda a,b: a+b, list1, list2)
print(list(result))

# itertools, heapq, bisect, collections - deque Counter, math

hi = sum([1,2,3,4,5])
print(hi)
min_result = min(7,3,5,2)
max_result = max(7,3,5,2)
print(min_result, max_result)
result = eval("(3+5)*7")
print(result)

result = sorted([9,1,8,5,4])
reverse_result = sorted([9,1,8,5,4], reverse=True)
print(result)
print(reverse_result)
array = [('홍길동', 35), ('이순신', 75), ('아무개', 50)]
result = sorted(array, key = lambda x: x[1], reverse = True)
print(result)

## 순열 조합
from itertools import permutations, combinations, product, combinations_with_replacement

data = ['A', 'B', 'C']
result = list(permutations(data, 3))
print(result)
result = list(combinations(data, 2))
print(result)
result = list(product(data, repeat=2))
print(result)
result = list(combinations_with_replacement(data, 2))
print(result)

## Counter : 등장횟수 카운트
from collections import Counter
counter = Counter([1,2,3,4,5,5,5,5,5,5])
print(counter['5'])
print(dict(counter))

## Math
import math
def lcm(a,b): 
  return a*b // math.gcd(a,b)

print(math.gcd(21,14))
print(lcm(21,14))