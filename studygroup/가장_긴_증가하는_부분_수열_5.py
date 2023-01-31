import sys
import bisect as bs
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
d = [0] * (N + 1)
LIS = [a[0]]

for i in range(1, N):
    if LIS[-1] < a[i]:
        LIS.append(a[i])
        d[i] = len(LIS) - 1
    else:
        d[i] = bs.bisect_left(LIS, a[i])
        LIS[d[i]] = a[i]

idx = max(d) + 1
print(idx)

ans = []
for i in range(N - 1, -1, -1):
    if d[i] == idx - 1:
        ans.append(a[i])
        idx = d[i]

print(*ans[::-1])
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 100만, LIS의 길이, 수열 자체 출력

2. d[i] = max(d[j]) + 1, j < i, a[j] < a[i]
'''
