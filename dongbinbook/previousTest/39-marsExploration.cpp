#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321

int T;            // 10
int N;            // 125
int a[125][125];  // 최대 9
int d[125][125];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                d[i][j] = INF;
            }
        }

        int x = 0, y = 0;
        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push({-a[x][y], {0, 0}});
        d[x][y] = a[x][y];
        while (!pq.empty()) {
            int dist = -pq.top().first;  // maxheap
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (d[x][y] < dist) continue;  // 현재 노드가 이미 처리됬으면 패스
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
                int c = dist + a[nx][ny];
                if (c < d[nx][ny]) {
                    d[nx][ny] = c;
                    pq.push({-c, {nx, ny}});
                }
            }
        }
        cout << d[N - 1][N - 1] << '\n';
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         cout << d[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    return 0;
}
