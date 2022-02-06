#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void calc(int m, int n, int x, int y) {
    --x, --y;
    bool flag = false;

    for (int i = x; i < m * n; i += m) {
        if (i % n == y) {
            cout << i + 1 << endl;
            flag = true;
            break;
        }
    }

    if (!flag) cout << -1 << endl;
}

int main() {
    FASTIO;

    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        calc(m, n, x, y);
    }

    return 0;
}
