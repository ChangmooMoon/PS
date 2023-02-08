import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

N = int(si())
board = [si().rstrip() for _ in range(N)]
visited = [[False for _ in range(N)] for _ in range(N)]

group = [0] * 626
cnt = 0


def dfs(r, c, g):
    visited[r][c] = True
    group[g] += 1
    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if 0 <= nr < N and 0 <= nc < N and board[nr][nc] == '1' and not visited[nr][nc]:
            dfs(nr, nc, g)


for i in range(N):
    for j in range(N):
        if board[i][j] == '1' and not visited[i][j]:
            cnt += 1
            dfs(i, j, cnt)

group.sort()

print(cnt)
for i in range(626 - cnt, 626):
    print(group[i])
