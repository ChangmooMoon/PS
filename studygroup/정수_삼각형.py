import sys
si = sys.stdin.readline

N = int(si())
a = [list(map(int, si().split())) for _ in range(N)]
d = [[0 for _ in range(N)] for _ in range(N)]

d[0][0] = a[0][0]
for i in range(1, N):
    for j in range(0, i + 1):
        if j == 0:
            d[i][j] = d[i - 1][j] + a[i][j]
        elif j == i:
            d[i][j] = d[i - 1][j - 1] + a[i][j]
        else:
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j]

print(max(d[N - 1]))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 높이 n 1~500, 삼각형에서 합이 최대가 되는 경로에 있는 수의 합

d[i][j] = 왼쪽 위, 아랫쪽 위에서 오는 값 중 최대값 + a[i][j]
d[i][j] = max(d[i - 1][[j - 1], d[i - 1][j]])
맨 왼쪽, 맨 오른쪽 케이스 예외처리












'''
