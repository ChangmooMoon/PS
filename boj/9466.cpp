#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 사이클

int t, n;
int a[100001], check[100001]; // 0 방문x, -1사이클, 123방문

void dfs(int s) {
    int now = s;
    while (1) {
        check[now] = s;
        now = a[now];
        if (check[now] == s) {
            while (check[now] != -1) {
                check[now] = -1;
                now = a[now];
            }
            return;
        }
        if (check[now]) return;
    }
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(check, 0, sizeof(check));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!check[i]) dfs(i);
        }
        for (int i = 1; i <= n; ++i) {
            if (check[i] != -1) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
