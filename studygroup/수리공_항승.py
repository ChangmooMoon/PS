import sys
si = sys.stdin.readline

N, L = map(int, si().split())
a = list(map(int, si().split()))
a.sort()

ans = 0
s = a[0]
for i in range(1, N):
    d = a[i] - s
    if L <= d:
        ans += 1
        s = a[i]
print(ans + 1)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 물이 세는 위치, 테이프 길이 L, 테이프를 사용해야되는 최소갯수
N 1000, L 1000
그 위치의 좌우 0.5만큼 간격을 줘야 물이 안센다

2. 브루트포스. 맨 처음 새는 곳부터 L 사용해서 붙이면서 1개씩 카운트
'''
