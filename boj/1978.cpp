#include <iostream>
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
using namespace std;

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    FASTIO;
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (prime(a)) ++cnt;
    }

    cout << cnt;
    return 0;
}
