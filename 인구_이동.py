from collections import *
import heapq as hq
import functools
import re
import sys
import math
import bisect as bs
from typing import *
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
N, L, R = map(int, si().split())
a = [list(map(int, si().split())) for _ in range(N)]
g = None


def bfsAndMerge(r, c, gIdx):
    q = deque([])
    q.append((r, c))
    g[r][c] = gIdx
    gSize, total = 1, a[r][c]  # 칸, 총인구
    while q:
        r, c, = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < N and 0 <= nc < N:
                if L <= abs(a[r][c] - a[nr][nc]) <= R:
                    q.append((nr, nc))
                    gSize += 1
                    total += a[r][c]

    #     if gSize == N * N:
    #         return False  # 종료조건

    #     for i in range(N):
    #         for j in range(N):
    #             if g[r][c] == gIdx:
    #                 a[i][j] = total // gSize
    # return True


ans, gIdx = 0, 0
while True:
    g = [[0 for _ in range(N)] for _ in range(N)]  # 그룹 정보
    for i in range(N):
        for j in range(N):
            if g[i][j] == 0:
                gIdx += 1
                flag = bfsAndMerge(i, j, gIdx)
                if not flag:
                    print(ans)
                    sys.exit(0)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N*N 그리드, a[r][c]에 사람 몇명
인구이동
- [L, R] 차이나면 인접한 칸끼리 하루동안 인구 이동
- 각각의 칸 값 = 연합의 인구수 / 연합을 이루는 칸의 갯수, 소수점 버린다
N 1~50, L, R 1~100
인구이동 일수 ~2000보다 작음
인구이동이 몇일동안 일어나는지 출력

2. 같은 그룹끼리 묶고, 각 그룹마다 총합과 칸 갯수를 카운트해서 나눈 값을 일일이 다 넣어준다
-> dfs로 풀었다가 이전 위치 인구값이 필요해서 bfs로 변경해서 품
'''
