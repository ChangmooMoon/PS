#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[1000];
int d[1001][1001]; // d[i][cnt]

int go(int idx, int cnt) {
    if (idx == n)
        return 0;

    int &ans = d[idx][cnt];
    if (ans != -1)
        return ans;

    int b = m - cnt + 1; // *****xxxxx|
    int c = b * b;
    ans = go(idx + 1, a[idx] + 1) + c;
    if (cnt + a[idx] <= m) {
        int cur = go(idx + 1, cnt + a[idx] + 1);
        if (ans > cur)
            ans = cur;
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(1, a[0] + 1);
    return 0;
}
