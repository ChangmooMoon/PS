#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[1000], d[1001];

int solve(int s) {
    int& ret = d[s + 1];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = s + 1; i < n; ++i) {
        if (s == -1 || a[s] < a[i])
            ret = max(ret, solve(i) + 1);
    }
    return ret;
}

// LIS
int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    memset(d, -1, sizeof(d));
    cout << solve(-1) - 1;
    return 0;
}
