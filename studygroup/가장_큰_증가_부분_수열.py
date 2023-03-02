import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
d = [0] * (N + 1)

d[0] = a[0]
for i in range(1, N):
    d[i] = a[i]
    for j in range(i):
        if a[j] < a[i]:
            d[i] = max(d[i], d[j] + a[i])

print(max(d))
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 1000, a[i] 1000 증가부분수열 중에 합이 가장 큰 것
2. d[i] = 증가부분수열의 최대합
d[i] = d[i - 1] + a[i]

2. d[i] = a[i]를 포함하는 LIS의 합
d[i] = max(d[j] + a[i]), j < i, a[j] < a[i]
'''
