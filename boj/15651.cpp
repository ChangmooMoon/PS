#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[8];
bool check[8];

void go(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        check[i] = true;
        a[idx] = i;
        go(idx + 1);

        check[i] = false;
    }
}

// 중복순열
int main() {
    FASTIO;
    cin >> n >> m;
    go(0);

    return 0;
}
