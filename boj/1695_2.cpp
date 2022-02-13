#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// dp, 메모이제이션 예시

int n;
int a[5001], d[5001][5001];
// d[i][j] = min(d[i+1][j], d[i][j-1]) +1 (a[i] != a[j])

int go(int s, int e) {
    if (s >= e) return 0;
    if (d[s][e] != -1) return d[s][e];
    if (a[s] == a[e])
        return d[s][e] = go(s + 1, e - 1);
    else
        return d[s][e] = min(go(s + 1, e), go(s, e - 1)) + 1;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(1, n);
    return 0;
}
