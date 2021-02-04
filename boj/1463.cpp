#include <algorithm>
#include <iostream>
using namespace std;

int d[1000001];
int x;  // x1000000

int go(int n) {
    if (n == 1) return 0;
    if (d[n] > 0) return d[n];

    int tmp;
    d[n] = go(n - 1) + 1;
    if (n % 2 == 0) {
        tmp = go(n / 2) + 1;
        if (d[n] > tmp) d[n] = tmp;
    }
    if (n % 3 == 0) {
        tmp = go(n / 3) + 1;
        if (d[n] > tmp) d[n] = tmp;
    }
    return d[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> x;
    cout << go(x);

    return 0;
}
