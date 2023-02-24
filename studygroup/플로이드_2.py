import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f

N, M = int(si()), int(si())
d = [[INF for _ in range(N + 1)] for _ in range(N + 1)]
nxt = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    d[i][i] = 0

for _ in range(M):
    a, b, c = map(int, si().split())
    d[a][b] = min(d[a][b], c)
    nxt[a][b] = b


for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if d[i][k] + d[k][j] < d[i][j]:
                d[i][j] = d[i][k] + d[k][j]
                nxt[i][j] = nxt[i][k]

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if d[i][j] == INF:
            print(0, end=" ")
        else:
            print(d[i][j], end=" ")
    print()

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if d[i][j] in (0, INF):
            print(0)
        else:
            path = []
            st = i
            while st != j:
                path.append(st)
                st = nxt[st][j]
            path.append(j)

            print(len(path), end=" ")
            print(*path, sep=" ")

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. n*n줄을 출력하는데 
'''
