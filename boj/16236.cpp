#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, sr, sc, ans;
int a[20][20];
bool check[20][20];

struct Shark {
    int r, c, d;
    bool operator<(const Shark& other) const {
        if (d == other.d) {
            if (r == other.r) return c > other.c;
            return r > other.r;
        }
        return d > other.d;
    }
};

void bfs(int sr, int sc) {
    int size = 2, exp = 0;
    priority_queue<Shark> pq;
    pq.push({sr, sc, 0});
    check[sr][sc] = true;

    while (!pq.empty()) {
        int r, c, d;
        r = pq.top().r;
        c = pq.top().c;
        d = pq.top().d;
        pq.pop();

        if (a[r][c] && a[r][c] < size) {
            a[r][c] = 0;
            ans += d;
            d = 0;
            ++exp;
            if (exp == size) {
                ++size;
                exp = 0;
            }
            memset(check, false, sizeof(check));
            pq = priority_queue<Shark>();
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || n <= nr || n <= nc) continue;
            if (check[nr][nc]) continue;
            if (a[nr][nc] > 0 && a[nr][nc] > size) continue;

            pq.push({nr, nc, d + 1});
            check[nr][nc] = true;
        }
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                sr = i, sc = j;
                a[i][j] = 0;
            }
        }
    }

    bfs(sr, sc);
    cout << ans;
    return 0;
}
