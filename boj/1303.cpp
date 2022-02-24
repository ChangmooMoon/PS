#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, w, b;
string a[100];

int dfs(int i, int j, char ch) {
    if (0 > i || 0 > j || n <= i || m <= j || a[i][j] != ch) return 0;
    a[i][j] = 'X';
    return 1 + dfs(i + 1, j, ch) + dfs(i - 1, j, ch) + dfs(i, j - 1, ch) + dfs(i, j + 1, ch);
}

int main() {
    FASTIO;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'W') {
                int p = dfs(i, j, 'W');
                w += p * p;
            } else if (a[i][j] == 'B') {
                int p = dfs(i, j, 'B');
                b += p * p;
            }
        }
    }
    cout << w << ' ' << b;
    return 0;
}
