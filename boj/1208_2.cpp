#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, k;
int a[41];
vector<int> v1, v2;

void dfs(int s, int e, int c, vector<int>& v) {
    if (s == e) {
        v.push_back(c);
        return;
    }
    dfs(s + 1, e, c + a[s], v);
    dfs(s + 1, e, c, v);
}

int check(int y) {
    return upper_bound(v2.begin(), v2.end(), y) - lower_bound(v2.begin(), v2.end(), y);
}

ll solve() {
    dfs(0, n / 2, 0, v1);
    dfs(n / 2, n, 0, v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll ret = 0;
    for (int x : v1) {
        ret += check(k - x);
    }

    if (k == 0) --ret;
    return ret;
}

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve();
    return 0;
}
