#include <iostream>
#include <vector>
using namespace std;

int n, s, ans;  // 20, 1000000

// 2^20 = 100만
void go(vector<int>& v, int idx, int sum) {
    if (idx == n) {
        if (sum == s) {
            ans++;
        }
        return;
    }

    go(v, idx + 1, sum + v[idx]);
    go(v, idx + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    go(v, 0, 0);
    if (s == 0) ans--;  // 공집합 제외

    cout << ans;
    return 0;
}
