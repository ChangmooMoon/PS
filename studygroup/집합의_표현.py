import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M = map(int, si().split())
p = [0] * (N + 1)

for i in range(1, N + 1):
    p[i] = i


def find(x):  # union-find
    if x == p[x]:
        return x
    p[x] = find(p[x])
    return p[x]


def union(a, b):
    a, b = find(a), find(b)
    if a < b:
        p[b] = a
    else:
        p[a] = b


for _ in range(M):
    cmd, a, b = map(int, si().split())
    if cmd == 0:  # 합집합
        union(a, b)
    else:  # 같은 집합인지 체크
        print("YES" if find(a) == find(b) else "NO")
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 0, 1, 2, ...n 집합이 있음
- 합집합 연산, 두 원소가 같은 집합인지 확인하는 연산 2가지 연산이 있음

n 100만, M 10만
합집합은 0 a b
두 원소가 같은 집합인지 확인 1 a b

2. 합집합이 주어지면 해당 그룹을 합집합한다
같은 집합 체크가 주어지면 그 부모를 비교해서 같으면 yes, 아니면 no 출력한다
'''
