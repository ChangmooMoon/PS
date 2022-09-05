// 새로운 불면증 치료법
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;

int solve(int sheep) {
    int cnt = 0, ret = 0;
    while (ret != 1023) {
        ++cnt;
        int num = sheep * cnt;

        while (num) {
            ret |= 1 << (num % 10);
            num /= 10;
        }
    }
    return cnt * sheep;
}

int main() {
    FASTIO;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        cout << '#' << i << ' ' << solve(n) << endl;
    }
    return 0;
}
