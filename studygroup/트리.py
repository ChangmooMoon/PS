from collections import *
import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(cur):
    ret = 0
    for next in a[cur]:
        if next != target:
            ret += dfs(next)

    return 1 if not ret else ret


N = int(si())
p = list(map(int, si().split()))
a = defaultdict(list)
target = int(si())
root = -1

for v in range(N):
    u = p[v]
    if u == -1:
        root = v
    else:
        a[u].append(v)

print(0 if root == target else dfs(root))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 리프노드는 자식의 갯수가 0인 노드
노드 하나를 지우면 그 노드를 루트로 하는 서브트리가 제거됨
그 때 리프노드의 갯수 리턴
N 50, 0~N-1노드깍지 각 노드의 부모가 주어짐, 부모없으면 -1
지울 노드 주어짐

2. 부모노드 정보가 주어짐
부모정보로 트리 그리고, dfs로 탐색, target 노드이면 탐색 중지

'''
