#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef long long ll;

// 9876543210: 10! = 326만
ll bfs(int n) {
    int cnt = 0;
    queue<ll> q;
    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        ++cnt;
        if (cnt == n) return now;
        // if (cnt > 1000000) break;

        for (int i = 0; i < now % 10; ++i) {
            ll next = now * 10 + i;
            q.push(next);
        }
    }

    return -1;
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    cout << bfs(n);
    return 0;
}
