#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> a[20001];
vector<int> check(20001);

void dfs(int x, int group) {
    check[x] = group;  // 0,1,2
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (check[y] == 0) {
            dfs(y, 3 - group);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    for (int i = 0; i < k; ++i) {
        int node, edge;  // node 20000, edge 200000
        cin >> node >> edge;

        for (int i = 1; i <= node; ++i) {
            a[i].clear();
        }
        fill(check.begin(), check.end(), 0);

        for (int i = 0; i < edge; ++i) {
            int u, v;
            cin >> u >> v;
            a[u].emplace_back(v);
            a[v].emplace_back(u);
        }

        for (int i = 1; i <= node; ++i) {
            if (check[i] == 0) {
                dfs(i, 1);
            }
        }

        bool ans = true;
        for (int i = 1; i <= node; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                int y = a[i][j];
                if (check[i] == check[y]) {
                    ans = false;
                }
            }
        }

        ans ? cout << "YES" : cout << "NO";
        cout << '\n';
    }

    return 0;
}
