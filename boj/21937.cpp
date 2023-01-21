#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, M, X;
vector<int> a[100001];
bool visited[100001];
int ans = 0;

void dfs(int cur, int step) {
    visited[cur] = true;
    for (int prev : a[cur]) {
        if (!visited[prev]) {
            ++ans;
            dfs(prev, step + 1);
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        a[v].push_back(u);
    }
    cin >> X;
    dfs(X, 0);
    cout << ans;
    return 0;
}
