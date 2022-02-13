#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

bool check[20001];
pair<int, char> a[20001];  // from, digit01

void solve(int MOD) {
    memset(check, false, sizeof(check));
    queue<int> q;
    q.push(1);
    check[1] = true;
    a[1] = {-1, '1'};  // 맨첨

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i <= 1; ++i) {
            int next = (now * 10 + i) % MOD;
            if (check[next]) continue;

            a[next] = {now, i + '0'};
            if (next == 0) return;

            q.push(next);
            check[next] = true;
        }
    }
}

void print(int i) {
    if (i == -1) return;
    print(a[i].first);

    cout << a[i].second;
}

int main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1)
            cout << 1 << endl;
        else {
            solve(n);
            print(0);
            cout << endl;
        }
    }

    return 0;
}
