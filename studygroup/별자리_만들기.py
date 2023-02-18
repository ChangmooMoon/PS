from collections import *
import sys
import math
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

V = int(si())
a = []
edge = []
p = [_ for _ in range(V + 1)]
ans = 0

for _ in range(V):
    u, v = map(float, si().split())
    a.append((u, v))

for i in range(V):
    for j in range(i + 1, V):
        sx, sy = a[i]
        ex, ey = a[j]
        d = math.sqrt((sx - ex) ** 2 + (sy - ey) ** 2)
        edge.append((d, i, j))

edge.sort()


def Find(x):
    if p[x] != x:
        p[x] = Find(p[x])
    return p[x]


def Union(a, b):
    a, b = Find(a), Find(b)
    if a < b:
        p[b] = a
    else:
        p[a] = b


for el in edge:
    w, u, v = el
    if Find(u) != Find(v):
        Union(u, v)
        ans += w

print(f'{ans:.2f}')

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. n개의 별들을 이어서 별자리를 만듬. 모든 별들은 이어져있음
별자리를 만드는 최소비용

N 100, x,y 좌표가 실수로 주어짐, 소수점 둘째자리, -1000~1000

2. 좌표 받아서 모든 간선의 거리 담아서 비용순으로 정렬해서 uf
'''
