#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321
#define pii pair<int, int>

// 최단경로 - 다익스트라

struct Edge {
    int to, weight;
};

int n, m, start;
vector<Edge> a[300001];
vector<int> dist(20001, INF);
vector<bool> check(20001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> start;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back({y, w});
    }

    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();

        if (check[x]) continue;
        check[x] = true;
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i].to;
            if (dist[y] > dist[x] + a[x][i].weight) {
                dist[y] = dist[x] + a[x][i].weight;
                pq.push({dist[y], y});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] >= INF)
            cout << "INF" << ' ';
        else
            cout << dist[i] << ' ';
    }

    return 0;
}
