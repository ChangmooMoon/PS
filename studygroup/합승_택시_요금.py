INF = 0x3f3f3f3f


def solution(n, s, a, b, fares):
    d = [[INF] * (n + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        d[i][i] = 0

    for u, v, w in fares:
        d[u][v] = d[v][u] = w

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]

    ans = INF
    for mid in range(1, n + 1):
        res = d[s][mid] + d[mid][a] + d[mid][b]
        ans = min(ans, res)

    return ans


'''
1. A, B가 합승을 해서 집에 감
4에서 출발, 6, 2가 집, 두 사람이 귀가하는 최저요금

1~N 노드, 무방향 간선, 4 -> 1 -> 5까지 도착해서 중간에 갈라짐 5->6, 5->3->2

N노드 200, s출발, a도착, b도착, a!=b
fares 2차원, fares[i] u,v,w

2. 
(start -> 중간지점) + (중간지점 -> A) + (중간지점 -> B) 이 최소인 값 리턴
s, a, b가 주어짐. 중간지점만 찾으면 됨 -> 플로이드
중간지점이 start랑 같을 수도 있음 - 시작부터 각자 택시타는 경우
'''
