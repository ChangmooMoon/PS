#include <iostream>
using namespace std;

void solve(int n, int x, int y) {
    if (n == 0) return;

    int tmp = 6 - x - y;
    solve(n - 1, x, tmp);
    cout << x << ' ' << y << '\n';
    solve(n - 1, tmp, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int d[n + 1];  // n개의 원판으로 이루어진 하노이탑 최소이동횟수
    d[1] = 1;      //
    for (int i = 2; i <= n; ++i) {
        d[i] = 2 * d[i - 1] + 1;
    }

    cout << d[n] << '\n';
    solve(n, 1, 3);

    return 0;
}
