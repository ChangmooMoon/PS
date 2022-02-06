#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
vector<int> a[3005];
int check[3005];
int d[3005];

// -2: 사이클제외, -1: 사이클없어서끝나는지점 1:시작점 2:사이클포함
int go(int x, int past) {
    if (check[x] == 1) return x;  // 시작점

    check[x] = 1;
    for (int y : a[x]) {
        if (y == past) continue;

        int res = go(y, x);  // 시작정점의 값 or -2
        if (res == -2) return -2;
        if (res >= 0) {
            check[x] = 2;
            if (x == res) return -2;
            return res;
        }
    }
    return -1;
}

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (check[i] == 2) {
            q.push(i);
            d[i] = 0;
        }
    }

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int y : a[n]) {
            if (d[y] >= 0) continue;
            d[y] = d[n] + 1;
            q.push(y);
        }
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    go(1, -1);
    memset(d, -1, sizeof(d));
    bfs();
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    return 0;
}
