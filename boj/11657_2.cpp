#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
// SPFA, 음수사이클

int n, m;
vector<pii> a[501];
bool check[501];
int cnt[501];
ll d[501];

bool go(int s) {
    queue<int> q;
    q.push(s);
    check[s] = true;
    d[s] = 0;
    ++cnt[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        check[u] = false;
        for (pii next : a[u]) {
            int v, w;
            tie(v, w) = next;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!check[v]) {
                    check[v] = true;
                    q.push(v);
                    if (++cnt[v] >= n) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
    }

    if (!go(1)) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        if (d[i] == INF) d[i] = -1;
        cout << d[i] << endl;
    }

    return 0;
}
