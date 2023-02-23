from collections import *
from heapq import heappush, heappop
import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f


def dijk(st, en) -> int:
    q = []
    d = [INF] * (V + 1)

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
    return d[en]


V, E = map(int, si().split())
a = defaultdict(list)
for _ in range(E):
    u, v, w = map(int, si().split())
    a[u].append((w, v))
    a[v].append((w, u))
mid1, mid2 = map(int, si().split())
ans = INF

path1 = dijk(1, mid1) + dijk(mid1, mid2) + dijk(mid2, V)
path2 = dijk(1, mid2) + dijk(mid2, mid1) + dijk(mid1, V)
ans = min(ans, path1, path2)

print(-1 if ans >= INF else ans)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 1 - N으로 최단거리 이동. 임의의 주어진 두 개이 정점은 반드시 통과해야됨
V 800 E 20만, u,v,w 1000, mid1, mid2가 주어짐

2. s -> mid1 -> mid2 -> e, s -> mid2 -> mid1 -> e 최단거리 계산
'''
