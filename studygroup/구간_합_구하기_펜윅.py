import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, K = map(int, si().split())
arr = [0] * (N + 1)
tree = [0] * (N + 1)


def update(i, diff):
    while i <= N:
        tree[i] += diff
        i += (i & -i)


def prefix_sum(i):
    ret = 0
    while i > 0:
        ret += tree[i]
        i -= (i & -i)
    return ret


for i in range(1, N + 1):
    arr[i] = int(si())
    update(i, arr[i])

for i in range(M + K):
    a, b, c = map(int, si().split())
    if a == 1:
        update(b, c - arr[b])
        arr[b] = c
    else:
        print(prefix_sum(c) - prefix_sum(b - 1))


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 수N 100만개, 수의 변경M 1만, K 구간의 합 쿼리 갯수 1만
a가 1이면 b를 c로 바꿈
a 2이면 [b, c]범위의 합 출력

2. 동적 구간합 세그먼트트리, 펜윅트리

'''
