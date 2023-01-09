import sys
from collections import deque
input = sys.stdin.readline

dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
r, c, size, feed, time = 0, 0, 2, 0, 0

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            r, c = i, j
            break


def bfs(sr, sc, size):
    d = [[0]*N for _ in range(N)]
    visited = [[False]*N for _ in range(N)]
    small_fish = []

    q = deque([(sr, sc)])
    visited[sr][sc] = True

    while q:
        r, c = q.popleft()
        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc] and board[nr][nc] <= size:
                q.append((nr, nc))
                visited[nr][nc] = True
                d[nr][nc] = d[r][c] + 1
                if 0 < board[nr][nc] < size:
                    small_fish.append((d[nr][nc], nr, nc))

    return sorted(small_fish, key=lambda x: (x[0], x[1], x[2]))


while True:
    fish_list = bfs(r, c, size)

    if len(fish_list) == 0:
        break

    dist, nr, nc = fish_list.pop(0)
    board[r][c], board[nr][nc] = 0, 0
    time += dist
    feed += 1

    if feed == size:
        size += 1
        feed = 0
    r, c = nr, nc

print(time)
