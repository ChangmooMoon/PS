#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 트리순회
int n;
vector<int> a[100001];
int p[100001];
bool check[100001];

void go(int now) {
    check[now] = true;
    for (int next : a[now]) {
        if (check[next]) continue;
        p[next] = now;
        go(next);
    }
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v), a[v].push_back(u);
    }
    go(1);
    for (int i = 2; i <= n; ++i) {
        cout << p[i] << endl;
    }
    return 0;
}
