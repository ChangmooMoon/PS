#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[2001];
int d[2001][2001];

int isPalin(int i, int j) {
    if (i == j) return 1;
    if (j - i == 1) {
        if (a[i] == a[j]) return 1;
        return 0;
    }

    if (d[i][j] == 1) return d[i][j];

    if (a[i] != a[j]) return d[i][j] = 0;
    return d[i][j] = isPalin(i + 1, j - 1);
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << isPalin(s, e) << endl;
    }

    return 0;
}
