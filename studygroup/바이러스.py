import sys
from typing import *
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M = int(si()), int(si())
a = [[False for _ in range(N + 1)] for _ in range(N + 1)]
d = [False] * (N + 1)
ans = 0

for _ in range(M):
    s, e = map(int, si().split())
    a[s][e] = a[e][s] = 1


def dfs(s: int):
    d[s] = True
    for i in range(1, N + 1):
        if a[s][i] and not d[i]:
            global ans
            ans += 1
            d[i] = True
            dfs(i)


dfs(1)
print(ans)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 100 이하, 1~100까지 넘버링, 무방향 연결그래프 주어짐
바이러스 걸리는 컴퓨터수 카운트

2. N 100이하니까 인접행렬 그려서 그래프 그리고, dfs로 전파
'''
