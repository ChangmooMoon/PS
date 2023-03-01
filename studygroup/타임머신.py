import sys
from typing import *
si = sys.stdin.readline
INF = 0x3f3f3f3f

N, M = map(int, si().split())
edges = []
d = [INF] * (N + 1)

for _ in range(M):
    u, v, w = map(int, si().split())
    edges.append((u, v, w))


def bf(st) -> bool:
    d[st] = 0
    for i in range(N):
        for j in range(M):
            u, v, w = edges[j]
            if d[u] != INF and d[v] > d[u] + w:
                d[v] = d[u] + w
                if i == N - 1:
                    return True
    return False


negative_cycle = bf(1)

if negative_cycle:
    print(-1)
else:
    for i in range(2, N + 1):
        if d[i] == INF:
            print(-1)
        else:
            print(d[i])


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 도시의 갯수 500, M 노선이 갯수 6000, A시작 B도착 1~500, C비용 -1만~1만
C가 양수가 아닌경우 있음. 0이면 순간이동, -이면 타임머신
도시1에서 나머지도시로 가는 가장 빠른 시간 출력

- 음수사이클이 생기면 -1
- 아니면 2~N번 도시로 가는 가장 빠른 시간을 순서대로 출력
- 해당 도시로 가는 경로 없으면 -1
'''
