#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#define pii pair<int, int>
using namespace std;

const int dr[6] = {-2, -2, 0, 0, 2, 2};
const int dc[6] = {-1, 1, -2, 2, -1, 1};

int n, r1, c1, r2, c2;
int map[201][201];
int dist[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r1 >> c1 >> r2 >> c2;
    memset(dist, -1, sizeof(dist));
    queue<pii> q;
    q.push({r1, c1});
    dist[r1][c1] = 0;

    while (!q.empty()) {
        int r, c;
        tie(r, c) = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || nr >= n || 0 > nc || nc >= n) continue;
            if (dist[nr][nc] != -1) continue;

            q.push({nr, nc});
            dist[nr][nc] = dist[r][c] + 1;
        }
    }

    cout << dist[r2][c2];
    return 0;
}
