#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

long long d[31][31];

long long go(int w, int h) {
    long long &ret = d[w][h];
    if (ret != -1) return ret;
    if (w == 0) return 1;
    if (h == 0) return ret = go(w - 1, h + 1);
    return ret = go(w - 1, h + 1) + go(w, h - 1);
}

int main() {
    FASTIO;
    memset(d, -1, sizeof(d));
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << go(n, 0) << endl;
    }

    return 0;
}
