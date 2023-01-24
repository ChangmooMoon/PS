import sys
si = sys.stdin.readline

d0, d1 = [0] * 41, [0] * 41
d0[0], d0[1] = 1, 0
d1[0], d1[1] = 0, 1

for i in range(2, 41):
    d0[i] = d0[i - 1] + d0[i - 2]
    d1[i] = d1[i - 1] + d1[i - 2]

T = int(si())
for _ in range(T):
    N = int(si())
    print(d0[N], d1[N], sep=' ')
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. fib(N)을 호출했을 때 fib(0), fib(1)이 호출되는 횟수 각각 구하기
d[N] = fib(N)에서 0이 출력되는 횟수
d2[N] = fib(N)에서 1이 출력되는 횟수
d[i] = d[i - 1] + d[i - 2]
d2[i] = d2[i - 1] + d2[i - 2]
'''
