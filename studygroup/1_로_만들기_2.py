import sys
si = sys.stdin.readline

N = int(si())
d = [0 for _ in range(N + 1)]
pre = [-1 for _ in range(N + 1)]

for i in range(2, N + 1):
    d[i] = d[i - 1] + 1
    pre[i] = i - 1

    if not i % 2 and d[i] > d[i // 2] + 1:
        d[i] = d[i // 2] + 1
        pre[i] = i // 2
    if not i % 3 and d[i] > d[i // 3] + 1:
        d[i] = d[i // 3] + 1
        pre[i] = i // 3

print(d[N])
curr = N
while True:
    print(curr, end=' ')
    if curr == 1:
        break
    curr = pre[curr]

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 연산 3개를 이용해서 1을 만드는 최소횟수 찾기
- not X % 3 이면 X /= 3
- not X % 2 이면 X /= 2
- X -= 1
N 1~100만

2. 경로 찾는 문제. 이전 경로 저장하는 배열 하나 더 있어야
d[i] = 1에서 i에 도달하는 최소연산 횟수
pre[i] = i가 어떤 값으로부터 왔는지 
'''
