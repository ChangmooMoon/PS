#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

// 다익스트라
int n, m;
vector<pii> a[1001]; // v, w
int d[1001], num[1001];
bool check[1001];

int go(int s, int e) {
    priority_queue<pii> q; // w, x
    q.push({0, s});
    d[s] = 0, num[s] = 1;

    while (!q.empty()) {
        int w = -q.top().first, x = q.top().second;
        q.pop();
        if (check[x]) continue;
        check[x] = true;
        for (pii p : a[x]) {
            int y, nw;
            tie(y, nw) = p;
            if (d[y] > d[x] + nw) {
                d[y] = d[x] + nw;
                q.push({-d[y], y});
            }
            if (d[y] < w) num[x] += num[y];
        }
    }
    return num[e];
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w}), a[v].push_back({u, w});
    }
    memset(d, INF, sizeof(d));
    cout << go(2, 1);
    return 0;
}
