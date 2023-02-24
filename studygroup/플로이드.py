import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f

N, M = int(si()), int(si())
d = [[INF for _ in range(N + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    d[i][i] = 0

for _ in range(M):
    a, b, c = map(int, si().split())
    d[a][b] = min(d[a][b], c)


for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if d[i][k] + d[k][j] < d[i][j]:
                d[i][j] = d[i][k] + d[k][j]

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if d[i][j] == INF:
            print(0, end=" ")
        else:
            print(d[i][j], end=" ")
    print()

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 도시, 버스 M개, 모든 도시 쌍에 대해서 A->B 로 가는 비용이 최소값
N 100, M 10만, u,v,w i->j로 못가면 0 출력

2. 플로이드와샬
'''
