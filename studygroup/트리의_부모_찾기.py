import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(si())
p = [0] * (N + 1)
a = [[] * (N + 1) for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, si().split())
    a[u].append(v)
    a[v].append(u)


def dfs(curr):
    for next in a[curr]:
        if p[curr] != next:
            p[next] = curr
            dfs(next)


dfs(1)

for i in range(2, N + 1):
    print(p[i])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 루트없는 트리 주어짐. 루트가 1일 때 각 노드의 부모 출력
N 2~10만
'''
