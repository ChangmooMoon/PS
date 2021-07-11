#include <iostream>
#define INF 987654321;
using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const itn dc[4] = {0, 0, -1, 1};

int n, ans = INF;
int a[21][21];  // 400 * 100 = 40000
int group[21][21];

int solve(int x, int y) {
    for (int d1)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int diff = solve(i, j);
            ans = min(ans, diff);
        }
    }

    cout << ans;
    return 0;
}
