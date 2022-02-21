#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int t[1500001], p[1500001], d[1500001];

int go(int i) {
    if (i >= n) return 0;

    int &ret = d[i];
    if (ret != -1) return ret;
    ret = 0;
    if (i + t[i] <= n) ret = max(ret, go(i + t[i]) + p[i]);
    ret = max(ret, go(i + 1));
    return ret;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> p[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(0);
    return 0;
}