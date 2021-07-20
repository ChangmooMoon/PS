#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<pair<int, int>> graph[10001];  // to, weight;


// d[i] = max()
void dfs(int) {
    int
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dfs(1);
    cout << ans;
 
    return 0;
}
