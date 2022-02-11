#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
vector<int> a[32001];
bool check[32001];

void go(int x) {
    check[x] = true;
    for (int y : a[x]) {
        if (!check[y]) go(y);
    }
    cout << x << ' ';
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!check[i]) go(i);
    }
    return 0;
}