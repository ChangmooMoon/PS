from collections import *
import sys
si = sys.stdin.readline

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
N, M = map(int, si().split())
a = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
d = [[-1 for _ in range(M + 1)] for _ in range(N + 1)]
for i in range(N):
    a[i + 1][1:] = list(map(int, *si().split()))


def bfs(sr, sc):
    q = deque([])
    q.append((sr, sc))
    d[sr][sc] = 1

    while q:
        r, c = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 1 <= nr <= N and 1 <= nc <= M:
                if a[nr][nc] == 1 and d[nr][nc] == -1:
                    q.append((nr, nc))
                    d[nr][nc] = d[r][c] + 1
                    if nr == N and nc == M:
                        return d[nr][nc]


print(bfs(1, 1))
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N*M 배열 미로, 1 이동할 수 있는 칸, 0은 이동할 수 없는 칸
(1,1) -> (N, M)의 위치에 도달하는 최소이동칸수

2. (1,1)에서 시작하는 bfs로 거리 카운트, 거리단위 1
'''
