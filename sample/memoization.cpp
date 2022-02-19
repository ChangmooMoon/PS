#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int d[31][31];

// 메모이제이션
int bino(int n, int r) {
    if (r == 0 || r == n) return 1;
    if (d[n][r] != -1) return d[n][r];
    return d[n][r] = bino(n - 1, r - 1) + bino(n - 1, r);
}

int main() {
    FASTIO;
    memset(d, -1, sizeof(d));
    cout << bino(30, 15) << endl;
    cout << bino(28, 3) << endl;
    return 0;
}
