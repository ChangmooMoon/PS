#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 이분그래프
int n, m;
vector<int> a[20005];
bool check[20005];
bool color[20005];

bool dfs(int cur) {
    for (int next : a[cur]) {
        if (!check[next]) {
            check[next] = true;
            color[next] = !color[cur];
            bool res = dfs(next);
            if (!res) return false;
        } else if (color[cur] == color[next]) {
            return false;
        }
    }
    return true;
}

bool solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        a[i].clear();
        color[i] = false;
        check[i] = false;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            check[i] = true;
            bool res = dfs(i);
            if (!res) return false;
        }
    }
    return true;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        if (solve())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}
