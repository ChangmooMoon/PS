#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
vector<int> a[32001];  // 문제번호는 난이도순
int ind[32001];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        ++ind[v];
    }

    priority_queue<int> q;  // 최소힙
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(-i);
        }
    }

    while (!q.empty()) {
        int x = -q.top();
        q.pop();
        cout << x << ' ';

        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            --ind[y];
            if (ind[y] == 0) q.push(-y);
        }
    }

    return 0;
}
