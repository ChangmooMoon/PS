from collections import *
import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(cur, prev):
    d[cur] = 1
    for next in a[cur]:
        if prev == next:
            continue
        d[cur] += dfs(next, cur)
    return d[cur]


N, R, Q = map(int, si().split())
a = defaultdict(list)
d = [0] * (N + 1)

for _ in range(N - 1):
    u, v = map(int, si().split())
    a[u].append(v)
    a[v].append(u)

dfs(R, 0)

for _ in range(Q):
    print(d[int(si())])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 무방향 간선이 있는 루트있는 트리
U를 루트로 하는 서브트리에 속한 정점의 수
N 10만, R루트번호, Q10만
u, v형태의 간선 정보
Q줄에 걸쳐서 U가 주어짐. 그러면 해당 U를 루트로 하는 서브트리에 속한 정점의 수 구한다

2. 일단 그래프를 그리는데 인접리스트로 받음 N^2 100억
쿼리도 10만개니까 각 노드에서 시작하는 트리를 미리 구해놓는다. 
플러드필을 해서 각각의 그룹을 구해놓고, 그 그룹의 갯수를 구해놓는다
인접리스트라서 bfs를 할 수 가 없다???

2. 탑다운 dp, 
'''
