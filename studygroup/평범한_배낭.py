import sys
si = sys.stdin.readline

N, K = map(int, si().split())
d = [[0] * 101 for _ in range(100001)]
W, V = [0] * 101, [0] * 101

for i in range(1, N + 1):
    W[i], V[i] = map(int, si().split())

for i in range(1, N + 1):
    for j in range(1, K + 1):
        d[i][j] = d[i - 1][j]
        if j - W[i] >= 0:
            d[i][j] = max(d[i][j], d[i - 1][j - W[i]] + V[i])

print(d[N][K])


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 물건, 무게w, 가치v를 가진다. 최대 k 만큼의 무게를 넣을 수 있음
넣을 수 있는 가치의 최대값

N 100, K 10만, w 10만, v 1000

2. 
- 모든 조합 0000~1111 2^N
- 모든 무게에 대해서 각각의 물건을 넣거나 빼는 경우

d[i][j] = 물건 i를 담았을 때 무게는 j일 때의 최대 가치
d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i])


'''
