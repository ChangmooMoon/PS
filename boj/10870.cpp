#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, d[21];

int go(int i) {
    if (i == 0) return 0;
    if (i == 1 || i == 2) return 1;
    int &ret = d[i];
    if (ret != -1) return ret;
    return d[i] = go(i - 1) + go(i - 2);
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    memset(d, -1, sizeof(d));
    cout << go(n);

    return 0;
}
