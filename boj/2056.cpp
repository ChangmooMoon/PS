#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> graph[10001];
vector<int> ind(10001);
vector<int> t(10001);
vector<int> d(10001);  // 작업 끝나는 시간

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> t[i] >> m;
        for (int j = 0; j < m; ++j) {
            int u;
            cin >> u;
            graph[u].push_back(i);
            ind[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            d[i] = t[i];
        }
    }  // 초기화

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            ind[v]--;
            if (ind[v] == 0) {
                q.push(v);
            }
            if (d[v] < d[u] + t[v]) {
                d[v] = d[u] + t[v];
            }
        }
    }

    cout << *max_element(d.begin(), d.end());

    return 0;
}
