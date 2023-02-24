import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f

N, M = map(int, si().split())
d = [[INF for _ in range(N + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    d[i][i] = 0

for _ in range(M):
    u, v = map(int, si().split())
    d[u][v] = d[v][u] = 1

for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if d[i][k] + d[k][j] < d[i][j]:
                d[i][j] = d[i][k] + d[k][j]

idx, ans = 0, INF
for i in range(1, N + 1):
    ret = 0
    for j in range(1, N + 1):
        ret += d[i][j]
    if ans > ret:
        idx = i
        ans = ret

print(idx)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

N 100 M 1000, A,B는 친구
케빈 베이컨의 수가 가장 적은 사람을 출력
'''
