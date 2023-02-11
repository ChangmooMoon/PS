from collections import *
import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, V = map(int, si().split())  # 정점갯수, 간선갯수, 탐색시작점
a = [[] * (N + 1) for _ in range(N + 1)]
d = [False] * (N + 1)
d2 = [False] * (N + 1)

for _ in range(M):
    u, v = map(int, si().split())
    a[u].append(v)
    a[v].append(u)

for i in range(N + 1):
    a[i].sort()


def dfs(curr):
    d[curr] = True
    print(curr, end=' ')

    for next in a[curr]:
        if not d[next]:
            dfs(next)


def bfs(curr):
    q = deque()
    q.append(curr)
    d2[curr] = True

    while q:
        curr = q.popleft()
        print(curr, end=' ')

        for next in a[curr]:
            if not d2[next]:
                d2[next] = True
                q.append(next)


dfs(V)
print()
bfs(V)
