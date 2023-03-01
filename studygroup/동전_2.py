import sys
si = sys.stdin.readline
INF = 0x3f3f3f3f

N, K = map(int, si().split())
a = [int(si()) for _ in range(N)]
d = [INF] * 10001

d[0] = 0
for i in range(N):
    for j in range(a[i], K + 1):
        d[j] = min(d[j], d[j - a[i]] + 1)

print(-1 if d[K] == INF else d[K])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N가지 종류 동전이 있음. 가치가 k원, 동전 갯수가 최소여야함. 동전은 무한으로 사용가능
구성이 같고 순서가 다른 경우는 같은 경우(조합)

N 100, K 1만, 가치 1~10만
최소갯수, 불가능하면 -1

2. 
d[i] = 동전 가치가 i일 때 사용한 동전의 최소갯수
d[i] = min(d[i], d[i - a[j] + 1]), i >= a[j]
'''
