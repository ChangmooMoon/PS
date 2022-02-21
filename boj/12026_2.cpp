#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n;
int a[1001], d[1001];

int go(int p) {
    if (p == n - 1) return 0;
    int &ret = d[p];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = p + 1; i < n; ++i) {
        if (a[i] == (a[p] + 1) % 3) {
            int space = i - p;
            ret = min(ret, go(i) + space * space);
        }
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'B')
            a[i] = 0;
        else if (ch == 'O')
            a[i] = 1;
        else
            a[i] = 2;
    }
    memset(d, -1, sizeof(d));
    int ans = go(0);
    cout << (ans == INF ? -1 : ans);
    return 0;
}
