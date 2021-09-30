#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[9];

void go(int idx, int start) {
    if (idx == m) {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; ++i) {
        a[idx] = i;
        go(idx + 1, i);
    }
}

// 중복조합 - O(n!) 방식이라서 비효율적
int main() {
    FASTIO;
    cin >> n >> m;
    go(0, 1);  // 4C2

    return 0;
}
