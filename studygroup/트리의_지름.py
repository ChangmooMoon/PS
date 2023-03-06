from collections import *
import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(cur, totalW):
    for w, next in a[cur]:
        if d[next] == -1:
            d[next] = totalW + w
            dfs(next, d[next])


N = int(si())
a = defaultdict(list)
d = [-1] * (N + 1)

for _ in range(N - 1):
    u, v, w = map(int, si().split())
    a[u].append((w, v))
    a[v].append((w, u))

d[1] = 0
dfs(1, 0)

node1 = d.index(max(d))
d = [-1] * (N + 1)
d[node1] = 0
dfs(node1, 0)

print(max(d))


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 트리가 주어짐. 트리의 지름 구하기
N 1만, N-1개의 u, v, w 가 주어짐
루트노드는 1, 부모노드 번호가 같으면 자식노드 번호가 같은게 먼저 입력됨

2. 가장 멀리있는 노드 거리를 찾으면 된다. 
노드1 - 루트 - 노드2 거리가 제일 멀면 지름임. 
루트에서 dfs로 탐색해서 거리가 제일 먼 노드거리 2개를 찾으면 된다?
- 공통부모가 1이 아니면 지름이 더 짧아지는걸 체크 못했음

2. 제일 긴 depth 노드 찾고, 거기서 ㄷ
'''
