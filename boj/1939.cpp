#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;
//  파라메트릭 서치, dfs, bfs
int n, m, s, e, ans;  // 섬1만, m다리10만, 공장1,공장2
vector<pair<int, int>> v[10001];
bool check[10001];

bool go(int node, int limit) {
    if (check[node]) return false;

    check[node] = true;
    if (node == e) return true;

    for (pii& p : v[node]) {
        int next = p.first;
        int weight = p.second;

        if (weight >= limit) {
            if (go(next, limit)) return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> s >> e;

    int l = 1, r = 1000000000;
    while (l <= r) {
        memset(check, false, sizeof(check));
        int mid = l + (r - l) / 2;

        if (go(s, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
