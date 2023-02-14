from collections import *
import sys
si = sys.stdin.readline

N, M = map(int, si().split())
a = [[] for _ in range(N + 1)]
ind = [0] * (N + 1)
order = [0] * (N + 1)

for _ in range(M):
    u, v = map(int, si().split())
    a[u].append(v)
    ind[v] += 1

q = deque()
for i in range(1, N + 1):
    if not ind[i]:
        q.append(i)
        order[i] = 1

while q:
    cur = q.popleft()
    for next in a[cur]:
        ind[next] -= 1
        if not ind[next]:
            order[next] = order[cur] + 1
            q.append(next)

print(*order[1:], sep=" ")

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 선수과목을 들어야됨. 선수과목을 듣고 그다음 과목을 들어야될 때 모든 과목들이 몇 학기 안에 이수할 수 있는지 출력
N 1~1000, M 0~50만, A < B
'''
