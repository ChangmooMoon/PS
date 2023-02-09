import sys
si = sys.stdin.readline

N, K = map(int, si().split())
d = [[_ for _ in range(101)] for _ in range(100001)]
w, v = [0] * 101, [0] * 101

for i in range(1, N + 1):
    w[i], v[i] = map(int, si().split())

for i in range(1, N + 1):
    for j in range(1, K + 1):
        d[i][j] = d[i - 1][j]
        if j - w[i] >= 0:
            d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i])

print(d[N][K])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 
물품의 수 N 100, 가방무게 K 10만, 물건의 무게 W 10만, 물건의 가치 V 1000

2. d[i][j] = 물건 i를 담았을 때 무게는 j일 때의 최대 가치
d[i][j] = max(d[i][j], d[i - 1][j - w[i]]) + v[i]

'''
