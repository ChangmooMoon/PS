#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, r;
vector<pii> graph[200001];  // u -> {v, weight}
bool check[200001];

pii findStem(int now, int totalW) {
    check[now] = true;

    if (graph[now].size() > 2 || graph[r].size() > 1) {
        return {now, totalW};
    }

    for (int i = 0; i < graph[now].size(); ++i) {
        const auto& [next, nextW] = graph[now][i];

        if (check[next]) continue;
        return findStem(next, totalW + nextW);
    }

    return {now, totalW};
}

int findBranch(int now, int totalW) {
    check[now] = true;
    if (graph[now].size() == 1) return totalW;

    int tmpW = 0;
    for (int i = 0; i < graph[now].size(); ++i) {
        const auto& [next, nextW] = graph[now][i];

        if (check[next]) continue;
        tmpW = max(tmpW, findBranch(next, totalW + nextW));
    }

    return tmpW;
}

int main() {
    FASTIO;

    cin >> n >> r;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    pii stem = findStem(r, 0);
    int branch = findBranch(stem.first, 0);

    cout << stem.second << ' ' << branch;
    return 0;
}
