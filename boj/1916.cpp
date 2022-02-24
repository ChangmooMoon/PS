#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

// 다익스트라
vector<pii> a[1001]; // from, {to, weight}
int d[1001];
bool check[1001];

int go(int s, int e) {
    priority_queue<pii> q; // w, v;
    q.push({0, s});
    d[s] = 0;

    while (!q.empty()) {
        int w, x;
        tie(w, x) = q.top();
        q.pop();
        if (check[x]) continue;
        check[x] = true;
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i].first;
            if (d[y] > d[x] + a[x][i].second) {
                d[y] = d[x] + a[x][i].second;
                q.push({-d[y], y});
            }
        }
    }
    return d[e];
}

int main() {
    FASTIO;
    int n, m, u, v, w, s, e;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    cin >> s >> e;
    memset(d, INF, sizeof(d));
    cout << go(s, e);
    return 0;
}
