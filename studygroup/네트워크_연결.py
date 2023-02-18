import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

V, E = int(si()), int(si())
a = []
p = [_ for _ in range(V + 1)]
ans = 0

for _ in range(E):
    u, v, w = map(int, si().split())
    a.append((w, u, v))
a.sort()


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
    w, u, v = el
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

1. V 1000, E 10만, E개의 선 u, v, w, w 1만, u, v는 같을 수 도 있음
2. 간선이 적으면 크루스칼, 많으면 프림
'''
