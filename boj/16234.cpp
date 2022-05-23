#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, L, R, ans;
int a[51][51];
bool check[51][51];

void dfs(int r, int c, int &country, int &people, vector<pair<int, int>> &route) {
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || N <= nr || N <= nc || check[nr][nc]) continue;

        int diff = abs(a[r][c] - a[nr][nc]);
        if (L <= diff && diff <= R) {
            people += a[nr][nc];
            ++country;
            check[nr][nc] = true;
            route.push_back({nr, nc});
            dfs(nr, nc, country, people, route);
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    while (1) {
        bool stop = true;
        memset(check, false, sizeof(check));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (check[i][j]) continue;

                vector<pair<int, int>> route;
                int country = 0, people = 0;
                dfs(i, j, country, people, route);

                if (!route.empty()) {
                    stop = false;
                    for (auto &[r, c] : route) {
                        a[r][c] = people / country;
                    }
                }
            }
        }

        if (stop) break;
        ++ans;
    }

    cout << ans;
    return 0;
}
