N = int(input())
plans = input().split()
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
move_types = ["L", "R", "U", "D"]


def solution(n, move):
    x, y = 1, 1
    for plan in plans:
        for i in range(4):
            if plan == move_types[i]:
                nx = x + dx[i]
                ny = y + dy[i]
        if nx < 1 or ny < 1 or nx > n or ny > n:
            continue
        x, y = nx, ny
    return (x, y)


print(solution(N, plans))
