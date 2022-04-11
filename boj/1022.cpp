#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
using namespace std;

int calc(int r, int c) {
    int n = max({r, c, -r, -c});
    int val = 2 * n + 1;
    val *= val;
    int diff = 2 * n;

    if (r == n) return val - n + c;
    val -= diff;
    if (c == -n) return val - n + r;
    val -= diff;
    if (r == -n) return val - c - n;
    val -= diff;
    return val - r - n;
}

int main() {
    FASTIO;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int maxw = 0;
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            int val = calc(i, j);
            int width = (int)(to_string(val).length());
            if (maxw < width) maxw = width;
        }
    }

    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            cout << setw(maxw) << calc(i, j) << ' ';
        }
        cout << endl;
    }
    return 0;
}
