#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, a[9];
bool check[9];

void go(int idx, int p) {
    if (p == m) {
        for (int i = 0; i < n; ++i) {
            if (check[i]) cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < n; ++i) {
        if (check[i]) continue;
        check[i] = true;
        go(i, p + 1);
        check[i] = false;
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    go(0, 0);
    return 0;
}
