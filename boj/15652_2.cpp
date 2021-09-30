#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[9];

// idx라는 수를 포함할지 O or X
void go(int idx, int pick) {
    if (pick == m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= a[i]; ++j) {
                cout << i << ' ';
            }
        }
        cout << endl;
        return;
    }

    if (idx > n) return;
    for (int i = m - pick; i >= 1; --i) {
        a[idx] = i;
        go(idx + 1, pick + i);
    }

    a[idx] = 0;
    go(idx + 1, pick);
}

// 중복조합
int main() {
    FASTIO;
    cin >> n >> m;
    go(1, 0);

    return 0;
}
