#include <algorithm>
#include <iostream>
using namespace std;

int k, n;
int a[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    long long l = 1, r = *max_element(a, a + k);
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += a[i] / mid;
        }

        if (cnt >= n) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
