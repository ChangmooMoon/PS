#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

ll solve(int n) {
    if (0 <= n && n <= 10) return n;
    vector<ll> ans;
    queue<ll> q;
    for (int i = 1; i <= 9; ++i) {
        q.push(i);
        ans.push_back(i);
    }
    while (!q.empty() && ans.size() <= n) {
        ll cur = q.front();
        q.pop();

        int digit = cur % 10;
        for (int i = 0; i < digit; ++i) {
            q.push(cur * 10 + i);
            ans.push_back(cur * 10 + i);
        }
    }
    if (ans.size() >= n)
        return ans[n - 1];
    else
        return -1;
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
