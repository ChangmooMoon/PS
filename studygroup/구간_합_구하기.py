import sys
from math import ceil, log2
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, K = map(int, input().split())
arr = [int(si()) for _ in range(N)]
H = ceil(log2(N)+1)
tree = [0] * (2**H)


def init(l, r, node):  # node가 지칭하고 있는 구간이 [l, r]이다.
    if l == r:
        tree[node] = arr[l]
        return
    mid = (l+r) // 2
    init(l, mid, node * 2)
    init(mid+1, r, node * 2 + 1)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def update(l, r, node, IDX, DIFF):  # arr[IDX]를 DIFF만큼 변경했을 때의 tree 변경
    if not (l <= IDX <= r):
        return
    tree[node] += DIFF
    if l == r:
        return
    mid = (l+r) // 2
    update(l, mid, node * 2, IDX, DIFF)
    update(mid+1, r, node * 2 + 1, IDX, DIFF)


def query(l, r, node, LEFT, RIGHT):  # [LEFT, RIGHT]의 구간 합을 구함.
    if r < LEFT or RIGHT < l:  # [l, r]이 [LEFT, RIGHT]를 완전히 벗어남.
        return 0
    if LEFT <= l and r <= RIGHT:  # [l, r]이 [LEFT, RIGHT] 안에 완전히 포함됨.
        return tree[node]
    mid = (l+r) // 2
    return query(l, mid, node*2, LEFT, RIGHT) + query(mid+1, r, node*2+1, LEFT, RIGHT)


init(0, N-1, 1)
for _ in range(M + K):
    a, b, c = map(int, si().split())
    if a == 1:
        b -= 1
        update(0, N-1, 1, b, c - arr[b])
        arr[b] = c  # arr도 갱신해주는 이유는... 오로지 diff 계산할 때 필요해서
    else:
        b -= 1
        c -= 1
        print(query(0, N-1, 1, b, c))


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 수, 수의 변경이 빈번함, 중간 부분합을 구한다. 1~K줄에 걸쳐 구한 구간의 합을 출력한다
N 100만-수의 갯수 M 1만수의 변경 횟수, K 1만-구간의 합을 구하는 횟수
a, b, c
a=1이면 b를 c로 바꾼다
a=2이면 b~c 범위의 합을 구한다

2. 구간합인데 빈번하게 바뀜. 세그먼트트리
'''
