import sys
input = sys.stdin.readline

N, M = map(int, input().split())
list = list(map(int, input().split()))
ans = 0

for i in range(1, 1 << N):  # 00001~11111
    ret = 0
    for j in range(N):
        if i & (1 << j):
            ret += list[j]
    if ret == M:
        ans += 1

print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 정수 N개, 1~N개 원소 가진 부분수열 중에 합이 S인 경우의 수
N 1~20, S ~100만, 원소 10만
2. 2^20 = 100만이니까 그냥 브루트포스로 다 계산
'''
