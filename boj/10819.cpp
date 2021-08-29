#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, ans;  // 8개의 정수
int a[8];
int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += abs(a[i] - a[i + 1]);
        }
        ans = max(ans, sum);
    } while (next_permutation(a, a + n));

    cout << ans;
    return 0;
}
