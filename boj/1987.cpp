#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int r, c, ans = 0;
string a[20];
bool check[20][20] = {false};
unordered_set<char> uset;

void go(int cnt, int x, int y) {
    check[x][y] = true;
    uset.insert(a[x][y]);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || r <= nx || 0 > ny || c <= ny) continue;
        if (uset.find(a[nx][ny]) != uset.end()) continue;

        ans = max(cnt + 1, ans);
        go(cnt + 1, nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < r; ++i) {
        cin >> a[i];
    }

    go(0, 0, 0);
    cout << ans;
    return 0;
}
