import sys
from typing import *
si = sys.stdin.readline
INF = 0x3f3f3f3f


def bf() -> bool:
    for i in range(N):
        for u, v, w in edges:
            if d[v] > d[u] + w:
                d[v] = d[u] + w
                if i == N - 1:
                    return True
    return False


TC = int(si())
for _ in range(TC):
    N, M, W = map(int, si().split())
    edges = []
    d = [INF] * (N + 1)

    for _ in range(M):
        u, v, w = map(int, si().split())
        edges.append((u, v, w))
        edges.append((v, u, w))

    for _ in range(W):
        u, v, w = map(int, si().split())
        edges.append((u, v, -w))

    negative_cycle = bf()
    print("YES" if negative_cycle else "NO")

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 
N개의 지점 사이에 M개의 도로, W개의 웜홀. 도로는 무향, 웜홀은 유향
웜홀로 가면 시간이 뒤로 감. 
TC가 주어지고, 음수사이클이 있는지 여부 출력
지점 1~N으로 매김, 두 지점을 연결하는 도로가 1개보다 많을 수 있음

TC 1~5, N 500, M 2500, W 200, T 0~1만
2~M+1줄에 도로 정보 S,E,T
M+2~M+W+1줄 웜홀의 정보 S E T
'''
