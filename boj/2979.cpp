#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int fee[4], a[101], ans = 0;

int main() {
    FASTIO;
    for (int i = 1; i <= 3; ++i) {
        cin >> fee[i];
    }

    for (int i = 0; i < 3; ++i) {
        int s, e;
        cin >> s >> e;
        ++a[s], --a[e];
    }

    int car = 0;
    for (int i = 1; i <= 100; ++i) {
        car += a[i];
        ans += car * fee[car];
    }
    cout << ans;
    return 0;
}
