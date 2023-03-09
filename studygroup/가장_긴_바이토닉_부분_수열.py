import sys
si = sys.stdin.readline

N = int(si())
a = [0] + list(map(int, si().split()))
d1, d2 = [0] * 1001, [0] * 1001

d1[1] = 1
for i in range(2, N + 1):
    d1[i] = 1
    for j in range(1, i):
        if a[j] < a[i]:
            d1[i] = max(d1[j] + 1, d1[i])

d2[1] = 1
for i in range(N, 0, -1):
    d2[i] = 1
    for j in range(N, i, -1):
        if a[j] < a[i]:
            d2[i] = max(d2[j] + 1, d2[i])

ans = 0
for i in range(1, N + 1):
    ans = max(ans, d1[i] + d2[i] - 1)
print(ans)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 1차원 배열 S[k - 1] < S[k] > S[k + 1] 이면 바이토닉 수열
가장 긴 바이토닉 수열의 길이 출력
N 1000

2. d1[i] = i번째에서 끝나는 가장 긴 LIS
d2[i] = i에서 끝나는 가장 긴 LDS

d1[i] = max(d[j]) + 1, a[i] < a[j], i < j
d2[i] = max(d[j]) + 1, a[i] > a[j], i < j


'''
