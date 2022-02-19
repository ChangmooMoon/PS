#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;
int a[501], d[501];

int solve(int s) {  // solve(i) = a[i] 에서 시작하는 LIS중 최대 길이
    int& ret = d[s + 1];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = s + 1; i < n; ++i) {
        if (s == -1 || a[s] < a[i]) {
            ret = max(ret, solve(i) + 1);
        }
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(-1) - 1 << endl;
    }

    return 0;
}