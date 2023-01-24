import sys
si = sys.stdin.readline

N = int(si())
a = [list(map(int, si().split())) for _ in range(N)]
d = [[-1 for _ in range(N)] for _ in range(N)]

d[0][0], d[0][1], d[0][2] = a[0][0], a[0][1], a[0][2]
for i in range(1, N):
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0]
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1]
    d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2]

print(min(d[N - 1][0:3]))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 집을 RGB로 칠해야되고 순서대로 비용 주어짐
- color[1] != color[2]
- color[N -1] != color[N]
- 2 <= i <= N - 1 일때 color[i] != color[i-1], color[i + 1]
N 2~1000, rgb 비용 주어짐. 모든 집을 칠하는 비용 최소값

2. 
인접한 집끼리 색이 같으면 안됨
케이스 3개
R로 시작 G로 시작 B로 시작
d[i][R] = i번째 집이 R일 때 여기까지 칠하는 비용의 최소값 
d[i][G]
d[i][B]

d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0]
d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1]
d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2]

d[0][0] = a[0][0], d[0][1] = a[0][1], d[0][2] = a[0][2]
'''
