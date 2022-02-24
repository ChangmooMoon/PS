#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, s;
int a[100001];

int solve(int l, int r) {
    int ans = 0;
    while (r <= n) {
        int sum = a[r] - a[l], len = r - l;
        if (sum < s)
            ++r;
        else {
            if (ans == 0 || ans > len) ans = len;
            ++l;
        }
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cout << solve(0, 1);
    return 0;
}
