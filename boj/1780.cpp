#include <iostream>
using namespace std;

int n;  // -1,0,1 종이
int a[2187][2187];
int ans[3];

bool check(int len, int r, int c) {
    for (int i = r; i < r + len; ++i) {
        for (int j = c; j < c + len; ++j) {
            if (a[i][j] != a[r][c]) return false;
        }
    }

    return true;
}

void solve(int len, int r, int c) {
    if (check(len, r, c)) {  // 다 같으면
        int num = a[r][c];
        ++ans[num + 1];
        return;
    }

    len /= 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            solve(len, r + i * len, c + j * len);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    solve(n, 0, 0);  // length, r, c

    for (int i = 0; i < 3; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
