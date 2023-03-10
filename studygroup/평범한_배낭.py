import sys
si = sys.stdin.readline

N, K = map(int, si().split())
W, V = [0], [0]
d = [[0] * (K + 1) for _ in range(N + 1)]
for _ in range(N):
    w, v = map(int, si().split())
    W.append(w)
    V.append(v)

for i in range(1, N + 1):
    for j in range(1, K + 1):
        if j < W[i]:
            d[i][j] = d[i - 1][j]
        else:
            d[i][j] = max(d[i - 1][j], d[i - 1][j - W[i]] + V[i])

print(d[N][K])
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 100개의 물건, 무게 w 10만, 가치v 1000, 가방 최대k10만
배낭에 넣을 수 있는 물건들의 가치의 최댓값
그리디로 못푸나?
d[i][j] = i번째 물건을 넣었을 때 무게는 j이고, 가방 물건의 가치

d[0][0] = 0

d[i][j]  = d[i - 1][j], j < W[i]
d[i][j] = d[i - 1][j - W[i]] + V[i], j >= W[i]

'''
