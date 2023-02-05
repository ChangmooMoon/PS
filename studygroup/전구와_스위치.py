import sys
si = sys.stdin.readline
inf = 0x3f3f3f3f

N = int(si())
a = [int(_) for _ in si().rstrip()]
t = [int(_) for _ in si().rstrip()]
ans = inf

# 첫번째 toggle 함
cnt = 0
arr = a[:]
for i in range(1, N):
    if arr[i - 1] != t[i - 1]:
        cnt += 1
        arr[i - 1] = 1 - arr[i - 1]
        arr[i] = 1 - arr[i]
        if i + 1 < N:
            arr[i + 1] = 1 - arr[i + 1]
if arr == t:
    ans = min(ans, cnt)

# 첫번째 toggle 안함
cnt = 1
arr = a[:]
arr[0], arr[1] = 1 - arr[0], 1 - arr[1]
for i in range(1, N):
    if arr[i - 1] != t[i - 1]:
        cnt += 1
        arr[i - 1] = 1 - arr[i - 1]
        arr[i] = 1 - arr[i]
        if i + 1 < N:
            arr[i + 1] = 1 - arr[i + 1]
if arr == t:
    ans = min(ans, cnt)

print(ans if ans != inf else -1)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개 스위치, 전구
주어진 상태를 만들 때 최소 스위치 누르는 횟수
N 2~10만, 불가능하면 -1

2. 10만^2 = 100억, O(N^2) 미만으로 풀어야됨

'''
