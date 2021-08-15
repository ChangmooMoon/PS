#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f;

int n, m, s, e;
vector<pii> graph[10001];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    return 0;
}
