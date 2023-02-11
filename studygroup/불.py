from collections import *
import sys
si = sys.stdin.readline

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
N, M = map(int, si().split())
a = [si().rstrip() for _ in range(N)]
d = [[-1 for _ in range(M)] for _ in range(N)]
d2 = [[-1 for _ in range(M)] for _ in range(N)]


def fire_bfs():
    q = deque()
    for i in range(N):
        for j in range(M):
            if a[i][j] == 'F':
                q.append((i, j))
                d[i][j] = 0

    while q:
        r, c = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < N and 0 <= nc < M:
                if a[nr][nc] != '#' and d[nr][nc] == -1:
                    q.append((nr, nc))
                    d[nr][nc] = d[r][c] + 1


def bfs():
    q = deque()
    for i in range(N):
        for j in range(M):
            if a[i][j] == 'J':
                q.append((i, j))
                d2[i][j] = 0

    while q:
        r, c = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if nr < 0 or N <= nr or nc < 0 or M <= nc:
                return d2[r][c] + 1
            if a[nr][nc] != '#' and d2[nr][nc] == -1:
                if d[nr][nc] == -1 or d[nr][nc] > d2[r][c] + 1:
                    q.append((nr, nc))
                    d2[nr][nc] = d2[r][c] + 1
    return "IMPOSSIBLE"


fire_bfs()
print(bfs())

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. r, c 1~1000, 미로가 주어짐. 탈출 가능여부 리턴, 가능하면 가장 빠른 탈출 시간
불은 상하좌우로 전파됨. 가장자리에 도달하면 탈출
#벽 .빈칸 j초기위치 F불

2. j가 가장자리에 도달하는 최소시간들을 다 찾고, 그 위치에 불도 도달하는 시간을 다 찾아서
서 안죽고 탈출하는 시간 중에 가장 빠른 시간 리턴, 없으면 IMPOSSIBLE 처리
지훈이는 1명, 불은 여러개일수도
'''
