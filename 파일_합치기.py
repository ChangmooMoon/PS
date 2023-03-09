from collections import *
from heapq import heappush, heappop
import functools
import re
import sys
import math
import bisect as bs
from typing import *
si = sys.stdin.readline
sys.setrecursionlimit(10**6)
INF = 0x3f3f3f3f


T = int(si())
for _ in range(T):
    K = int(si())
    a = list(map(int, si().split()))
    d = [[0] * K for _ in range(K)]

    for i in range(1, K):
        for j in range(1, K - i):
            d[j][i + j] = INF
            for k in range(j, i + j):
                d[j][i + j] = min(d[j][i + j], d[j][k] +
                                  d[k + 1][i + j] + sum[i + j] - sum[j - 1])


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 소설을 분할해서 씀. 두 파일을 합쳐서 임시파일, 계속 합쳐서 하나의 파일로 만듬
모든 장을 합치는 최소비용 출력
T, K 500, 

2. 
nC2 + n-1C2 + n-2C2 + ... + 2C2 = 500^3 = 12500만

f(p, q) = a[p]~a[q]까지 합치는 최소비용
f(p, q) = f(p, p) + f(p + 1, q) or f(p, p +1) + f(p + 2, q) or ...
d[i][j] = d[i][i] + d[i + 1][j] or .....
'''
