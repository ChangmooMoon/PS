#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// MST - prim 알고리즘
struct Edge {
    int to, cost;
    bool operator<(const Edge& other) const {
        return cost > other.cost;
    }
};

vector<Edge> graph[1001];
vector<bool> visit(1001);
int n, m;  // node, edge

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        graph[x].push_back(Edge({y, c}));
        graph[y].push_back(Edge({x, c}));
    }

    priority_queue<Edge> pq;
    visit[1] = true;
    for (Edge e : graph[1]) {
        pq.push(e);
    }

    int ans = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        int x = e.to;
        if (visit[x]) continue;

        visit[x] = true;
        cout << e.cost << endl;
        ans += e.cost;
        for (Edge next : graph[x]) {
            pq.push(next);
        }
    }

    cout << ans;
    return 0;
}
