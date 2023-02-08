import sys
si = sys.stdin.readline

N, M = map(int, si().split())
a = []
for _ in range(N):
    a.append(int(si()))

a.sort()

en, ans = 0, sys.maxsize
for st in range(N):
    while en < N and a[en] - a[st] < M:
        en += 1
    if en == N:
        break
    ans = min(ans, a[en] - a[st])

print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 정수 수열, 두 수를 골랐을 때 차이가 M 이상이면서 가장 작은 경우의 차이 찾기
N 1~10만, M 0~20억, ai: -10억~10억

2. 정렬하고, i, j 포인터의 값을 계속 계산해주면서 차이가 M 이상인 케이스이면서 차이가 작은 케이스 찾기
'''
