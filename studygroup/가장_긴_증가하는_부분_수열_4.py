import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
d = [1 for _ in range(N)]
prev = [-1] * N
LIS = []

for i in range(N):
    for j in range(0, i):
        if a[j] < a[i] and d[i] < d[j] + 1:
            d[i] = d[j] + 1
            prev[i] = j

print(max(d))

idx = d.index(max(d))
while idx != -1:
    LIS.append(a[idx])
    idx = prev[idx]

print(*LIS[::-1])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 수열의 LIS 길이, 그 부분수열 출력
N 1000이라 N^3 까지 가능

2. d[i] = a[i]를 마지막으로 하는 LIS 최대길이

d[i] = max(d[j]) + 1, j <i, a[j] < a[i]


'''
