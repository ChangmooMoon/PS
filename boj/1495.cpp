#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// O(2^n)으로 풀면 안됨 -> O(nm)
int n, s, m, ans = -1;  // s시작볼륨
int v[101];             // n음악 100개
bool d[101][1001];
// d[i][j] = i번 곡을 j로 볼륨j로 연주할 수 있으면 true, 아니면 false

int main() {
    FASTIO;
    int n, s, m;
    cin >> n >> s >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    d[0][s] = true;
    for (int i = 0; i <= n - 1; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (!d[i][j]) continue;

            if (j - v[i + 1] >= 0) d[i + 1][j - v[i + 1]] = true;
            if (j + v[i + 1] <= m) d[i + 1][j + v[i + 1]] = true;
        }
    }

    for (int i = 0; i <= m; ++i) {
        if (d[n][i]) ans = i;
    }

    cout << ans;
    return 0;
}
