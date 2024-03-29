import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
d = [1] * (N + 1)

for i in range(1, N):
    for j in range(i):
        if a[j] < a[i]:
            d[i] = max(d[i], d[j] + 1)

print(max(d))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. LIS 길이 
2. d[i] = a[i]를 포함하는 LIS의 길이
d[i] = max(d[j] + 1), j < i, a[j] < a[i]
'''
