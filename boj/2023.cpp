#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void go(int cur, int len) {
    if (len == n) {
        cout << cur << endl;
        return;
    }
    for (int n : {1, 3, 5, 7, 9}) {
        int next = cur * 10 + n;
        if (isPrime(next)) go(next, len + 1);
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i : {2, 3, 5, 7}) {
        go(i, 1);
    }
    return 0;
}
