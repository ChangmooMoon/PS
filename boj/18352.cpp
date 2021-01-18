#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int> >& list) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<int> > edge(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    cout << dfs(edge) << endl;
    return 0;
}
