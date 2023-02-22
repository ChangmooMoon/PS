from collections import *
from heapq import heappush, heappop
import sys
from typing import *
si = sys.stdin.readline
INF = 0x3f3f3f3f


def djik(st) -> list:
    d = [INF] * (V + 1)
    q = []
    d[st] = 0
    heappush(q, (0, st))

    while q:
        w, cur = heappop(q)
        if d[cur] < w:
            continue
        for nw, next in a[cur]:
            if w + nw < d[next]:
                d[next] = w + nw
                heappush(q, (d[next], next))
    return d


V, E, X = map(int, si().split())
a = defaultdict(list)
ans = 0

for _ in range(E):
    u, v, w = map(int, si().split())
    a[u].append((w, v))

d = djik(X)  # X -> 마을

for st in range(1, V + 1):
    ans = max(ans, d[st] + djik(st)[X])  # 마을st -> X

print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 마을, X마을에 모인다. M개의 단방향 도로, T(i) 1~100
그 마을에 갔다가 다시 돌아와야됨.
N명이 학생 중 가장 많은 시간을 소비하는 학생은?

V 1000, E 1만, X 모이는 마을
u, v, w 단방향 간선, a -> b가는 도로는 최대 1개

2. 각 마을마다 1명씩 살고 있음. 모든 마을에 대해서 마을 -> 파티지점 -> 마을 거리를 구해서 그 중 최대값을 출력
마을 -> 파티지점, 파티지점 -> 마을 각각 구하고 더해서 거리 찾기
'''
