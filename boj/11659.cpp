#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[100001];

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        cout << a[e] - a[s - 1] << endl;
    }
    return 0;
}
