from collections import *
from heapq import heappush, heappop
import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f

V, E = map(int, si().split())
st = int(si())
a = defaultdict(list)
d = [INF] * (V + 1)

for _ in range(E):
    u, v, w = map(int, si().split())
    a[u].append((w, v))


def dijk(st):
    pq = []

    d[st] = 0
    heappush(pq, (0, st))

    while pq:
        w, cur = heappop(pq)
        if d[cur] < w:
            continue
        for nw, next in a[cur]:
            if w + nw < d[next]:
                d[next] = w + nw
                heappush(pq, (d[next], next))


dijk(st)

for i in range(1, V + 1):
    print("INF" if d[i] == INF else d[i])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 주어진 시작점에서 다른 모든 정점으로의 최단경로  찾기
시작점 자신은 0, 경로가 없으면 INF로 출력
V 2만, E 30만
'''
