from collections import *
import sys
from copy import deepcopy
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
N, L, R = map(int, si().split())
a = [list(map(int, si().split())) for _ in range(N)]
g = None  # 연합 idx 저장
gSize = None  # 연합 칸 사이즈 저장
gTotal = None  # 연합 총인구 저장
ans = 0  # 인구이동 기간


def isSame(a, aa):
    for i in range(N):
        for j in range(N):
            if a[i][j] != aa[i][j]:
                return False
    return True


def dfs(r, c, gIdx):  # 연합 flood fill로 묶으면서 칸 사이즈, 총 인구 저장
    g[r][c] = gIdx
    gSize[gIdx] += 1
    gTotal[gIdx] += a[r][c]

    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if 0 <= nr < N and 0 <= nc < N:
            if g[nr][nc] == -1 and L <= abs(a[r][c] - a[nr][nc]) <= R:
                dfs(nr, nc, gIdx)


for _ in range(2000):
    aa = deepcopy(a)
    g = [[-1 for _ in range(N)] for _ in range(N)]
    gSize = [0] * 2501
    gTotal = [0] * 2501

    gCnt = 0  # 연합 갯수, 인덱스
    for i in range(N):
        for j in range(N):
            if g[i][j] == -1:
                gCnt += 1
                dfs(i, j, gCnt)  # 연합 flood fill로 묶기. 묶으면서 칸 사이즈, 총인구 저장

    for i in range(N):
        for j in range(N):
            gIdx = g[i][j]
            aa[i][j] = gTotal[gIdx] // gSize[gIdx]

    if isSame(a, aa):
        break

    a = deepcopy(aa)
    ans += 1

print(ans)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N*N 땅이 있고, a[r][c]에 인구수, 국경선 존재
- 인접한 땅끼리 인구차가 [L, R]이면 국경선 연다
- 열린 국경끼리 연합, 각 칸의 인구수 = 연합의 인구수 / 전체 칸 갯수
인구이동이 몇일동안 발생하는지 리턴
N 1~50, L, R 1~100

2. 인구이동 안할때까지 국경선 열고, 인구 합치고 반복
연합 범위를 flood fill로 묶어서 같은 그룹idx끼리 인구이동

'''
