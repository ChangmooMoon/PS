#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, k, s, ex, ey;  // n200*200,바이러스1~k가지, s초뒤, (x,y)좌표
int a[201][201];
int check[201][201];
vector<pair<int, int>> tmp;

bool cmp(pair<int, int>& u, pair<int, int>& v) {
    return a[u.first][u.second] < a[v.first][v.second];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    memset(check, -1, sizeof(check));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                tmp.push_back({i, j});  // 바이러스 시작점
                check[i][j] = 0;
            }
        }
    }

    sort(tmp.begin(), tmp.end(), cmp);
    for (auto i : tmp) {
        q.push(i);
    }

    cin >> s >> ex >> ey;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
                if (check[nx][ny] == -1) {
                    check[nx][ny] = check[x][y] + 1;
                    a[nx][ny] = a[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

    if (check[ex][ey] <= s)  // s초 이하로 도착했으면 성공
        cout << a[ex][ey];
    else
        cout << 0;

    return 0;
}
