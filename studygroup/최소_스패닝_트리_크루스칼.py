import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

V, E = map(int, si().split())
a = []
p = [_ for _ in range(V + 1)]
ans = 0

for _ in range(E):
    u, v, w = map(int, si().split())
    a.append((u, v, w))
a.sort(key=lambda x: x[2])


def Find(x):
    if p[x] != x:
        p[x] = Find(p[x])
    return p[x]


def Union(a, b):
    a, b = Find(a), Find(b)
    if (a < b):
        p[b] = a
    else:
        p[a] = b


for el in a:
    u, v, w = el
    if Find(u) != Find(v):
        Union(u, v)
        ans += w

print(ans)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. V 1만, E 1만, A B C u, v, w
최소 스패닝 트리의 가중치 찾기

2. 크루스칼 알고리즘
- 간선을 오름차순으로 정렬하고 제일 낮은 비용 간선을 선택
- u, v를 연결하는 간선일 때, u,v가 같은 그룹이면 그냥 넘어감
- u, v가 다른 그룹이면 같은 그룹으로 만들고, 선택한 간선을 최소신장트리에 추가을
'''
