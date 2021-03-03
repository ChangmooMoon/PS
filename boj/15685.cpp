#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
const int MAX = 100;

int n;  // 20
int a[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> v;
        v.push_back(d);
        for (int i = 0; i < g; ++i) {
            for (int j = v.size() - 1; j >= 0; --j) {
                v.push_back((v[j] + 1) % 4);
            }
        }

        a[x][y] = 1;
        for (int dir : v) {
            x += dx[dir];
            y += dy[dir];
            a[x][y] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}
