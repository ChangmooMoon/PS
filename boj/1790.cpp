#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long calcLen(int n) {
    long long ret = 0;
    for (int s = 1, len = 1; s <= n; s *= 10, ++len) {
        int e = s * 10 - 1;  // 1~9, 10~99, 100~999...
        if (e > n) e = n;
        ret += (long long)(e - s + 1) * len;
    }
    return ret;
}

long long solve(int n, int k) {
    long long len = calcLen(n);
    if (len < k) return -1;

    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (calcLen(mid) < k)
            l = mid + 1;
        else {
            r = mid - 1;
            ans = mid;
        }
    }

    string s = to_string(ans);
    return s[len - 1 - n + k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;  // 1~n까지의 수 1억, k번째숫자 10억
    cin >> n >> k;

    cout << solve(n, k);
    return 0;
}
