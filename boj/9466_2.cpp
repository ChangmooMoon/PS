#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 위상정렬

int t, n;
int a[100001], ind[100001];

int solve() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        --ind[a[now]];
        if (!ind[a[now]]) q.push(a[now]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) ++ans;
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(ind, 0, sizeof(ind));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++ind[a[i]];
        }
        cout << solve() << endl;
    }

    return 0;
}
