#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

bool check[9];
int a[9];
int n, m;

void go(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (check[i]) continue;

        check[i] = true;
        a[idx] = i;
        go(idx + 1);

        check[i] = false;
    }
}

// 1부 N까지 자연수 중에서 중복없이 M개를 고른 수열
// 순열
int main() {
    FASTIO;
    cin >> n >> m;
    go(0);  // 4P2
    return 0;
}
