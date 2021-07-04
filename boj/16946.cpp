#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
int a[1000][1000];
bool check[1000][1000];
int group[1000][1000];
vector<int> groupSize;

void bfs(int sx, int sy) {
    int g = groupSize.size();
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = true;
    group[sx][sy] = g;  // 0, 1,2,3, ...
    int cnt = 1;        // 자기자신 위치

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || 0 > ny || n <= nx || m <= ny) continue;
            if (a[nx][ny] == 0 && !check[nx][ny]) {
                q.push({nx, ny});
                check[nx][ny] = true;
                group[nx][ny] = g;
                cnt++;
            }
        }
    }
    groupSize.push_back(cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &a[i][j]);
            group[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0 && !check[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0)
                cout << 0;
            else {
                unordered_set<int> UDLR;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 > nx || 0 > ny || n <= nx || m <= ny) continue;
                    if (a[nx][ny] == 0) UDLR.insert(group[nx][ny]);
                }

                int ans = 1;
                for (int gNum : UDLR) {
                    ans += groupSize[gNum];
                }
                cout << ans % 10;
            }
        }
        cout << '\n';
    }

    return 0;
}
