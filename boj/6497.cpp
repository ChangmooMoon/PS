#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define union _union
using namespace std;

int parent[200001];

int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) return 0;

        vector<pair<int, pair<int, int>>> edges;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({z, {x, y}});
            ans += z;
        }

        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= m; ++i) {
            parent[i] = i;
        }
        sort(edges.begin(), edges.end());

        for (int i = 0; i < edges.size(); ++i) {
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;

            if (find(u) != find(v)) {
                union(u, v);
                ans -= w;
            }
        }

        cout << ans << '\n';
    }
}
