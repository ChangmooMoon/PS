from collections import *
from heapq import heappush, heappop
import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f


def dijk(st):
    q = []
    d[st] = 0
    heappush(q, (0, st))

    while q:
        w, cur = heappop(q)
        if d[cur] < w:
            continue
        for nw, next in a[cur]:
            if w + nw < d[next]:
                d[next] = d[cur] + nw
                heappush(q, (d[next], next))


V, E = int(si()), int(si())
a = defaultdict(list)
d = [INF] * (V + 1)
for _ in range(E):
    u, v, w = map(int, si().split())
    a[u].append((w, v))
st, en = map(int, si().split())

dijk(st)

print(d[en])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. st -> en 가는데 최소비용 출력
V 1000, E 10만
'''
