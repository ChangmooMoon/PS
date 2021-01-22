#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, start;  // node300,000 edge1000000 sdist300000 start1~300000
vector<int> a[300'001];
int check[300'001];
queue<int> q;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k >> start;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
    }

    memset(check, -1, sizeof(check));
    q.push(start);
    check[start] = 0;
    while (!q.empty()) {
        int x = q.front();
        if (check[x] == k) {
            ans.emplace_back(x);
        }
        q.pop();
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            if (check[y] == -1) {
                check[y] = check[x] + 1;
                q.push(y);
            }
        }
    }

    sort(ans.begin(), ans.end());
    if (ans.size() != 0) {
        for (int i : ans) {
            cout << i << '\n';
        }
    } else {
        cout << -1;
    }
    return 0;
}
