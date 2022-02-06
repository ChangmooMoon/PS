#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int main() {
    FASTIO;
    cin >> n;
    long long g = 0;

    for (int i = 1; i <= n; ++i) {
        g += n / i * i;  // i의배수의 갯수 (7 / 2) * 2 = 6
    }

    cout << g;
    return 0;
}
