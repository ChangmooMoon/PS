import sys
import bisect
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
LIS = [a[0]]  # LIS

for i in range(N):
    if LIS[-1] < a[i]:
        LIS.append(a[i])
    else:
        idx = bisect.bisect_left(LIS, a[i])
        LIS[idx] = a[i]

print(len(LIS))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 1~100만 이래 수열 a의 LIS의 길이 출려
N^2 미만으로 풀어야됨 nlogn

2. a[0] ~ a[i] 순회비용 O(N)
d[i]를 구하기 이해 d[k] 중 가장 큰 값을 logN 시간에 찾아야된다
LIS 자체를 dp table로 관리한다 분할정복

lowe_bound 사용
dp table 마지막 원소보다 a[i]가 크면 a[i]가 마지막 원소가 됨
a[i]가 작으면 dp table 중 a[i] 이상의 원소가 처음 등장하는 위치에 a[i]를 넣음
-> a[i] 이상의 원소가 처음 등장하는 위치를 찾기 위해서 lower_bound

'''
