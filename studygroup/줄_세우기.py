from collections import *
import sys
si = sys.stdin.readline

N, M = map(int, si().split())
a = [[] for _ in range(N + 1)]
ind = [0] * (N + 1)


for i in range(M):
    u, v = map(int, si().split())
    a[u].append(v)
    ind[v] += 1

q = deque()
for i in range(1, N + 1):
    if not ind[i]:
        q.append(i)

ans = []
while q:
    cur = q.popleft()
    ans.append(cur)
    for next in a[cur]:
        ind[next] -= 1
        if not ind[next]:
            q.append(next)
print(*ans, sep=" ")


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N명의 학생을 키순서대로 줄세운다. 두 학생의 키를 비교한 기록이 주어짐. 줄 출력
N 32000, M 10만

2. 인접리스트로 그래프 그리면서 동시에 indegree값 카운트, 이후 indegree가 0인 지점부터 그래프탐색
'''
