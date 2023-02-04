import sys
si = sys.stdin.readline

N, M = map(int, si().split())
a = list(map(int, si().split()))

i, j = 0, 0
sum, ans = a[0], 0

while j < N:
    if sum == M:
        ans += 1
    if sum <= M:
        j += 1
        if j < N:
            sum += a[j]
    else:
        sum -= a[i]
        i += 1
        
print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 수 수열, sum(a[i:j + 1]) 합이 M인 경우의 수 리턴
N 1~1만, M 1~3억, a[x] 3만미만

2. 10000^2= 1억이라서 N^2 안됨
투포인터으로 풀기
'''