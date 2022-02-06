#include <deque>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m;
vector<int> pos;

vector<vector<int>> bfs(vector<vector<char>>& a, int sr, int sc) {
    vector<vector<int>> d(n, vector<int>(m, -1));
    deque<pii> dq;
    dq.push_back({sr, sc});
    d[sr][sc] = 0;

    while (!dq.empty()) {
        int r, c;
        tie(r, c) = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || m <= nc || d[nr][nc] != -1) continue;
            if (a[nr][nc] == '*') continue;
            if (a[nr][nc] == '.') {
                dq.push_front({nr, nc});
                d[nr][nc] = d[r][c];
            } else {
                dq.push_back({nr, nc});
                d[nr][nc] = d[r][c] + 1;
            }
        }
    }
    return d;
}

int solve(vector<vector<char>>& a) {
    vector<vector<int>> d = bfs(a, 0, 0);
    vector<vector<int>> d2 = bfs(a, pos[0], pos[1]);
    vector<vector<int>> d3 = bfs(a, pos[2], pos[3]);

    int ret = n * m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*') continue;
            if (d[i][j] == -1 || d2[i][j] == -1 || d3[i][j] == -1) continue;
            int joint = d[i][j] + d2[i][j] + d3[i][j];
            if (a[i][j] == '#') joint -= 2;
            if (ret > joint) ret = joint;
        }
    }
    return ret;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        pos.clear();
        cin >> n >> m;
        n += 2, m += 2;
        vector<vector<char>> a(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    a[i][j] = '.';
                else {
                    cin >> a[i][j];
                    if (a[i][j] == '$') {
                        pos.push_back(i);
                        pos.push_back(j);
                        a[i][j] = '.';
                    }
                }
            }
        }

        cout << solve(a) << endl;
    }

    return 0;
}
