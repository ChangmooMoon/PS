import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
d = [0] * 1001

for i in range(N):
    d[i] = 1
    for j in range(i):
        if a[j] < a[i] and d[i] < d[j] + 1:
            d[i] = d[j] + 1
print(max(d))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 가장 긴 증가하는 부분수열 길이 찾기
N 1~1000

2. 
d[i] = a[1] ~ a[i]를 마지막으로 하는 LIS length
d[i] = max(d[j]) + 1, j <i, a[j] < a[i]
d[1] = 1
'''
