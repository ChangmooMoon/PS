#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[9];

// idx라는 수를 포함할지 O or X
void go(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    if (idx > n) return;

    a[cnt] = idx;
    go(idx + 1, cnt + 1);

    a[cnt] = 0;
    go(idx + 1, cnt);
}

// nCm 조합 - O(2^n) 이여서 n!보다 효율적
int main() {
    FASTIO;
    cin >> n >> m;
    go(1, 0);  // 4C2

    return 0;
}
