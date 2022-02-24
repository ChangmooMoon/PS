#include <iostream>
using namespace std;
typedef long long ll;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int main() {
    FASTIO;
    ll s, sum = 0, num = 0;
    cin >> s;

    for (ll i = 1; sum <= s; ++i) {
        if (sum + i <= s) {
            sum += i;
            ++num;
        } else {
            cout << num;
            break;
        }
    }
    return 0;
}
