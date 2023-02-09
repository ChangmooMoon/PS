from collections import *
import sys
from typing import *
si = sys.stdin.readline

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
M, N = map(int, si().split())
a = [list(map(int, si().split())) for _ in range(N)]  # -1빈칸 0안익음 1익음
d = [[-1 for _ in range(M)] for _ in range(N)]  # -1방문안함 0~ 방문


def bfs():
    q = deque([])
    for i in range(N):
        for j in range(M):
            if a[i][j] == 1:
                q.append((i, j))
                d[i][j] = 0

    while q:
        r, c = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < N and 0 <= nc < M:
                if a[nr][nc] == 0 and d[nr][nc] == -1:
                    q.append((nr, nc))
                    a[nr][nc] = 1
                    d[nr][nc] = d[r][c] + 1


def return_ans() -> int:
    ans = -1
    for i in range(N):
        for j in range(M):
            if a[i][j] == 0:
                return -1
            ans = max(ans, d[i][j])
    return ans


bfs()
print(return_ans())
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 토마토 보관, 상하좌우로 익은게 전파됨. 몇일이 지나면 다 익는지 최소일수 출력
세로 가로N, M 2~1000, 0안익은토마토, -1빈칸 1익은 토마토

2. 최소일수 구하니까 bfs로 제일 마지막에 도달하는 칸 출력
'''
