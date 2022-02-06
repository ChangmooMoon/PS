#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, s;
vector<int> a[1005];
bool check[1005];

void dfs(int i) {
    check[i] = true;
    cout << i << ' ';
    for (int j : a[i]) {
        if (!check[j]) dfs(j);
    }
}

void bfs(int i) {
    queue<int> q;
    check[i] = true;
    q.push(i);
    cout << i << ' ';

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j : a[x]) {
            if (!check[j]) {
                check[j] = true;
                q.push(j);
                cout << j << ' ';
            }
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(s);
    cout << endl;
    memset(check, false, sizeof(check));
    bfs(s);
    return 0;
}
