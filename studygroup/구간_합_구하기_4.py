import sys
si = sys.stdin.readline

N, M = map(int, si().split())
a = [0] + list(map(int, si().split()))

for i in range(1, N + 1):
    a[i] += a[i - 1]

for _ in range(M):
    s, e = map(int, si().split())
    print(a[e] - a[s - 1])


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 수 N개가 주어졌을 때 [i, j]의 합 범위 구하기
누적합 구하고, 해당 끝지점 누적합 - 시작지점 누적합
'''
