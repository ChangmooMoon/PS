#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;
int a[101][101], d[101][101];

// 메모이제이션
int can(int r, int c) {  // can(r,c) = r,c부터 맨 마지막 칸까지 도달 가능한지?
    if (n <= r || n <= c) return 0;
    if (r == n - 1 && c == n - 1) return 1;
    int& ret = d[r][c];
    if (ret != -1) return ret;
    return ret = can(r + a[r][c], c) || can(r, c + a[r][c]);
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        can(0, 0) == 1 ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}
