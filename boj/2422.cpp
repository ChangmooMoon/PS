#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, ans = 0;
vector<int> pick;
bool no[201][201];

void dfs(int idx, int len) {
    if (len == 3) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (no[pick[i]][pick[j]])
                    return;
            }
        }
        ++ans;
        return;
    }

    for (int i = idx + 1; i <= n; ++i) {
        if (no[idx][i])
            continue;
        pick.push_back(i);
        dfs(i, len + 1);
        pick.pop_back();
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        no[u][v] = no[v][u] = true;
    }

    dfs(0, 0);
    cout << ans;
    return 0;
}
