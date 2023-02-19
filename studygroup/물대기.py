import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(si())
a = []  # edges
p = [_ for _ in range(302)]
ans = 0
cnt = 0

for u in range(N):
    w = int(si())
    a.append((w, u, N))

board = [list(map(int, si().split())) for _ in range(N)]
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        w = board[i][j]
        a.append((w, i, j))
a.sort()


def Find(x):
    if p[x] != x:
        p[x] = Find(p[x])
    return p[x]


def Union(a, b):
    a, b = Find(a), Find(b)
    if a < b:
        p[b] = a
    else:
        p[a] = b


for el in a:
    w, u, v = el
    if Find(u) != Find(v):
        Union(u, v)
        ans += w
        cnt += 1
        if cnt == N:
            break

print(ans)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 300, w 10만, p(i,j) 1~10만
2. 우물을 캐는 최소비용 노드를 하나 찾고, 
그 노드를 시작점으로 해서 uf? 
반례가 생길것같음

2. 

'''
