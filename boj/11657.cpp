#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

// 최단거리 - 벨만포드 알고리즘
// 노드가 n개일 때 n-1개의 간선을 검사해서 최단거리를 구함
struct Edge {
    int from, to, weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;  // 도시500, 노선6000
    cin >> n >> m;
    vector<Edge> edge(m);                // 간선리스트
    vector<long long> dist(n + 1, INF);  // 시작점부터 i까지 가는 최단경로

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edge[i] = {from, to, weight};
    }

    dist[1] = 0;
    bool negative_cycle = false;
    for (int i = 1; i <= n; ++i) {     // 간선에 대해서 n-1번 검사, n번째에서 음수사이클 검사
        for (int j = 0; j < m; ++j) {  // 마을i로부터 나머지 마을까지의 최단경로를 모두 계산
            const auto& [x, y, w] = edge[j];

            if (dist[x] != INF && dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                if (i == n) {
                    negative_cycle = true;
                }
            }
        }
    }

    if (negative_cycle) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        if (dist[i] == INF) dist[i] = -1;

        cout << dist[i] << '\n';
    }

    return 0;
}
