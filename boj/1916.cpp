#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

struct Edge {
    int to, weight;
};

int n, m;                     // 노드, 엣지
vector<Edge> a[1001];         // 인접리스트
vector<int> dist(1001, INF);  // 최단거리
vector<bool> check(1001);     // 방문여부

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        a[from].push_back({to, weight});
    }
    int start, end;
    cin >> start >> end;
    dist[start] = 0;
    for (int k = 0; k < n - 1; ++k) {
        int d = INF + 1;
        int x = -1;
        for (int i = 1; i <= n; ++i) {
            if (!check[i] && d > dist[i]) {
                d = dist[i];
                x = i;
            }
        }

        check[x] = true;
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i].to;
            dist[y] = min(dist[y], dist[x] + a[x][i].weight);
        }
    }

    cout << dist[end];

    return 0;
}
