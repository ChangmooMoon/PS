#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 위상정렬

int t, k, m, p;
vector<int> a[1001], inflow[1001];
int ind[1001], order[1001];

int solve(int s) {
    queue<int> q;
    for (int i = 1; i <= m; ++i) {
        if (!ind[i]) {
            q.push(i);
            order[i] = 1;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (!order[cur]) {
            sort(inflow[cur].begin(), inflow[cur].end());
            int i = *inflow[cur].rbegin();
            if (count(inflow[cur].begin(), inflow[cur].end(), i) > 1)
                order[cur] = i + 1;
            else
                order[cur] = i;
        }
        for (int next : a[cur]) {
            inflow[next].push_back(order[cur]);
            --ind[next];
            if (!ind[next]) q.push(next);
        }
    }
    return order[m];
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(ind, 0, sizeof(ind));
        memset(order, 0, sizeof(order));
        cin >> k >> m >> p;
        for (int i = 1; i <= m; ++i) {
            a[i].clear();
            inflow[i].clear();
        }
        for (int i = 0; i < p; ++i) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            ++ind[v];
        }
        cout << k << ' ' << solve(1) << endl;
    }
    return 0;
}
