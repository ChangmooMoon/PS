import sys
si = sys.stdin.readline
inf = 0x3f3f3f3f

N = int(si())
d = [0] * (N + 1)

d[1] = 0
for i in range(2, N + 1):
    d[i] = min(d[i // 3] if not i % 3 else inf,
               d[i // 2] if not i % 2 else inf,
               d[i - 1]) + 1

print(d[N])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1.
X % 3 == 0 이면 X /= 3 한다
X % 2 == 0 이면 X /= 2 한다
X -= 1 한다
N 1~ 100만

2.
d[i] = 1을 만드는 연산의 횟수 최소값
d[i] = min(d[i / 3] if not i % 3, d[i / 2] if not i % 2, d[i - 1]) + 1
'''
