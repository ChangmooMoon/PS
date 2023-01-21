import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]

N, M = map(int, si().split())
board = [list(map(int, si().split())) for _ in range(N)]
T = int(si())
board2 = [[0 for _ in range(M)] for _ in range(N)]

for i in range(N):
    for j in range(0, len(board[i]), 3):
        if sum(board[i][j:j+3]) >= T * 3:
            nc = j // 3
            board2[i][j // 3] = 1

d = [[-1 for _ in range(M)] for _ in range(N)]
group = 0


def dfs(r, c, g):
    d[r][c] = g
    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if 0 <= nr < N and 0 <= nc < M and d[nr][nc] == -1 and board2[nr][nc] == 1:
            dfs(nr, nc, g)


for i in range(N):
    for j in range(M):
        if board2[i][j] == 1 and d[i][j] == -1:
            group += 1
            dfs(i, j, group)

print(group)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N*M 그리드, a(i, j) = rgb 평균내서 T보다 크면 255, 작으면 0
N, M 1000, rgb 255, T 255
rgb값이 T보다 크면 255, 작으면 0
rgb 같이 주어지고 평균으로 그리드에 넣어야
'''
