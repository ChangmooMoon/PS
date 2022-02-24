#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
vector<int> a[101];
bool check[101];

int dfs(int x) {
    if (check[x]) return 0;
    check[x] = true;
    int ret = 1;
    for (int y : a[x]) {
        ret += dfs(y);
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cout << dfs(1) - 1;

    return 0;
}
