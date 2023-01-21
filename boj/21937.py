import sys
sys.setrecursionlimit(10**6)
si = sys.stdin.readline

N, M = map(int, si().split())
a = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
ans = 0

for _ in range(M):
    u, v = map(int, si().split())
    a[v].append(u)

X = int(si())


def dfs(cur):
    global ans
    visited[cur] = True
    for prev in a[cur]:
        if not visited[prev]:
            ans += 1
            dfs(prev)


dfs(X)
print(ans)
