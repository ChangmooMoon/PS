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
                pre[next] = cur
                heappush(q, (d[next], next))


V, E = int(si()), int(si())
a = defaultdict(list)
d = [INF] * (V + 1)
pre = [0] * (V + 1)
for _ in range(E):
    u, v, w = map(int, si().split())
    a[u].append((w, v))
st, en = map(int, si().split())

dijk(st)

print(d[en])

ans = []
curr = en
while True:
    ans.append(curr)
    if curr == st:
        break
    curr = pre[curr]

print(len(ans))
print(*ans[::-1], sep=' ')


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 도시 1000개, 다른 도시로 가는 버스 10만개
A -> B로 가는 버스비용 최소화할 때, 최소비용, 경로 출력

2. 다익스트라로 최소비용 찾기, 찾으면서 이전 노드 저장
'''
