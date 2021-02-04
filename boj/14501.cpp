#include <algorithm>
#include <iostream>
using namespace std;

int n;      // 15 -> 2^15
int t[16];  // t[i] 5
int p[16];  // p[i] 1000

int ans = 0;

void calc(int day, int total) {
    if (day > n + 1) return;
    if (day == n + 1) {
        if (ans < total)
            ans = total;
        return;
    }
    calc(day + 1, total);
    calc(day + t[day], total + p[day]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }

    calc(1, 0);

    cout << ans;
    return 0;
}
