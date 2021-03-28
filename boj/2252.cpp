#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;  // 학생수32000, 비교횟수100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<int> graph[32001];
    vector<int> ind(32001);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        ind[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for (int i = 0; i < graph[x].size(); ++i) {
            int y = graph[x][i];
            ind[y]--;
            if (ind[y] == 0) q.push(y);
        }
    }

    return 0;
}
