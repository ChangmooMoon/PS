from collections import *
import heapq as hq
import sys
si = sys.stdin.readline

V, E = map(int, si().split())
a = defaultdict(list)
visited = [False] * (V + 1)

for _ in range(E):
    u, v, w = map(int, si().split())
    a[u].append((w, v))
    a[v].append((w, u))

heap = [[0, 1]]  # 탐색 시작점 idx 1
ans, cnt = 0, 0
hq.heapify(heap)

while heap:
    if cnt == V:
        break
    w, v = hq.heappop(heap)
    if not visited[v]:
        visited[v] = True
        ans += w
        cnt += 1
        for next in a[v]:
            hq.heappush(heap, next)

print(ans)
