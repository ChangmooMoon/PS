#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

long long solve(int a, int b, int c) {
    if (b == 1) return a % c;
    long long res = solve(a, b / 2, c);
    res = res * res % c;

    if (b & 1) return res * a % c;
    return res;
}

int main() {
    FASTIO;
    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c);
    return 0;
}
