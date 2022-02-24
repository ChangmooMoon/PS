#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
vector<int> a[101];
bool check[101];

int bfs(int s) {
    int ret = 0;
    queue<int> q;
    q.push(s);
    check[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : a[x]) {
            if (!check[y]) {
                q.push(y);
                check[y] = true;
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cout << bfs(1);

    return 0;
}
