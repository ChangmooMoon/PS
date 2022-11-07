#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

const int MAX_V = 20000;

int V, E, K;
int d[MAX_V + 1];
bool visited[MAX_V];
vector<pair<int, int>> a[20001];

int main() {
    FASTIO;
    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }

    for (int i = 1; i <= V; ++i) {
        d[i] = INF;
    }

    d[K] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({d[K], K});

    while (!pq.empty()) {
        auto [w, curr] = pq.top();
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto [next, nw] : a[curr]) {
            if (d[next] > d[curr] + nw) {
                d[next] = d[curr] + nw;
                pq.push({d[next], next});
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (d[i] == INF)
            cout << "INF" << endl;
        else
            cout << d[i] << endl;
    }

    return 0;
}
