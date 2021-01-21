#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int check[300][300];
int t;  // 300

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));
        int l;  // l*l 300*300
        cin >> l;

        int x, y, ex, ey;
        cin >> x >> y;    // 시작
        cin >> ex >> ey;  // 도착

        queue<pair<int, int>> q;
        q.push({x, y});
        check[x][y] = 1;

        while (!q.empty()) {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();

            for (int i = 0; i < 8; ++i) {
                int ix = nx + dx[i];
                int iy = ny + dy[i];
                if (0 <= ix && ix < l && 0 <= iy && iy < l) {
                    if (!check[ix][iy]) {
                        check[ix][iy] = check[nx][ny] + 1;
                        q.push({ix, iy});
                    }
                }
            }
        }
        cout << check[ex][ey] - 1 << '\n';
    }
    return 0;
}
