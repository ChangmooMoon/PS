import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

K = int(si())
a = list(map(int, si().split()))  # 중위순회 결과값
ans = [[] for _ in range(K)]


def make_tree(l, r, lv):
    if l == r:
        return
    mid = (l + r) // 2
    ans[lv].append(a[mid])

    make_tree(l, mid, lv + 1)
    make_tree(mid + 1, r, lv + 1)


make_tree(0, len(a), 0)
for i in range(K):
    print(*ans[i], sep=' ')

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 깊이가 K인 완전 이진트리, 2^K - 1개의 노드
K 1~10 2^10 - 1 = 1023

도시 방문 순서
- 루트 시작
- 왼쪽 자식으로 이동
- 왼쪽 자식이 없거나 왼쪽 자식 빌딩으로 들어왔으면, 현재 위치 저장
- 현재 빌딩을 다녀왔고, 오른쪽 자식 빌딩 있으면, 오른쪽으로 이동
- 현재 빌딩 오른쪽 왼쪽 빌딩 방분했으면 부모에게 이동 => 중위순회 왼루오

2. 완전 이진트리는 마지막레벨 제외하고 모든 레벨이 다 채워져있고, 마지막 레벨 모든 노드는 가능한 왼쪽에 있음
root의 위치는 len // 2
이걸 재귀적으로 이용해서 트리 그리자
'''
