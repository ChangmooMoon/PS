#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m, t, num;
vector<vector<int>> a(52);
bool check[52][52];

bool checkUDLR(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nc)
            nc += m;
        else if (m <= nc)
            nc -= m;

        if (a[nr][nc] == a[r][c])
            return true;
    }
    return false;
}

void dedupl() {
    memset(check, false, sizeof(check));

    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0)
                continue;
            if (checkUDLR(i, j)) {
                check[i][j] = true;
                flag = true;
            }
        }
    }

    if (flag) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (check[i][j])
                    a[i][j] = 0;
            }
        }
    } else {
        int total = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0)
                    continue;

                total += a[i][j];
                ++cnt;
            }
        }

        float avg = total / (float)cnt;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0)
                    continue;
                if (a[i][j] > avg)
                    --a[i][j];
                else if (a[i][j] < avg)
                    ++a[i][j];
            }
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m >> t;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n + 1) {
                a[i].push_back(0);
            } else {
                cin >> num;
                a[i].push_back(num);
            }
        }
    }

    while (t--) {
        int x, d, k;
        cin >> x >> d >> k;
        for (int i = x; i <= n; i += x) {
            if (d == 0) // right
                rotate(a[i].rbegin(), a[i].rbegin() + k, a[i].rend());
            else
                rotate(a[i].begin(), a[i].begin() + k, a[i].end());
        }
        dedupl();
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += a[i][j];
        }
    }
    cout << ans;
    return 0;
}
