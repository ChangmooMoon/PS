from collections import *
import sys
si = sys.stdin.readline

N, M = map(int, si().split())
d = [-1 for _ in range(200001)]


def bfs(s, e):
    q = deque()
    q.append(s)
    d[s] = 0

    while q:
        curr = q.popleft()
        if curr == e:
            return d[curr]

        if curr + 1 <= 200000 and d[curr + 1] == -1:
            q.append(curr + 1)
            d[curr + 1] = d[curr] + 1
        if curr - 1 >= 0 and d[curr - 1] == -1:
            q.append(curr - 1)
            d[curr - 1] = d[curr] + 1
        if curr * 2 <= 200000 and d[curr * 2] == -1:
            q.append(curr * 2)
            d[curr * 2] = d[curr] + 1
    return -1


print(bfs(N, M))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 수빈N, 동생K 0~10만
수빈은 x-1, x+1, 2*x로 이동할 수 있음
수빈 동생 위치 주어졌을 때, 수빈이 동생을 찾는 가장 빠른 시간?

2. bfs로 동생위치에 도달할 때까지 탐색. N 10만이여서 완전탐색 애매함 3^10만? 
'''
