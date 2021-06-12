#include <iostream>
using namespace std;

const int n = 9;
int a[10][10];  // 123456789 들어가야됨
bool check_r[10][10];
bool check_c[10][10];
bool check_s[10][10];

int square(int r, int c) {
    return (r / 3) * 3 + c / 3;
}

int go(int idx) {  // 9 * r + c
    if (idx > 80) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    int r = idx / n;
    int c = idx % n;  // 0 -> (0,0) 9 -> (1,0), 10 -> (1,1), 80 -> (8,8)
    if (a[r][c])
        return go(idx + 1);
    else {
        for (int i = 1; i <= 9; ++i) {
            if (!check_r[r][i] && !check_c[c][i] && !check_s[square(r, c)][i]) {
                check_r[r][i] = check_c[c][i] = check_s[square(r, c)][i] = true;
                a[r][c] = i;

                if (go(idx + 1)) return true;
                a[r][c] = 0;
                check_r[r][i] = check_c[c][i] = check_s[square(r, c)][i] = false;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                int num = a[i][j]; 
                int pos = (i / 3) * 3 + j / 3;
                check_r[i][num] = true;
                check_c[j][num] = true;
                check_s[pos][num] = true;
            }
        }
    }

    go(0);
    return 0;
}
