#include <cstring>
#include <iostream>
#include <queue>
#define size _size
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 1. d 오름차순, 2. 행 오름차순 // 3. 열 오름차순
struct Baby {
    int x, y, d;
    bool operator<(const Baby& other) const {
        if (d == other.d) {
            if (x == other.x) return y > other.y;
            return x > other.x;
        }
        return d > other.d;
    }
};

int n, size = 2, exp = 0, ans = 0;
int a[20][20];
int check[20][20];
priority_queue<Baby> pq;

void bfs() {
    while (!pq.empty()) {
        int x, y, d;
        x = pq.top().x;
        y = pq.top().y;
        d = pq.top().d;
        pq.pop();

        // 먹이랑 겹쳐진 상태
        if (a[x][y] > 0 && a[x][y] < size) {
            a[x][y] = 0;
            exp++;
            if (exp == size) {
                size++;
                exp = 0;
            }
            ans += d;

            memset(check, false, sizeof(check));
            d = 0;
            while (!pq.empty()) {
                pq.pop();
            }
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || 0 > ny || n <= nx || n <= ny) continue;
            if (check[nx][ny]) continue;
            if (a[nx][ny] > 0 && a[nx][ny] > size) continue;

            pq.push({nx, ny, d + 1});
            check[nx][ny] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                pq.push({i, j, 0});
                a[i][j] = 0;
            }
        }
    }

    bfs();
    cout << ans;

    return 0;
}
