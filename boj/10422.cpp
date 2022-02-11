#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MOD 1'000'000'007

int t, n;
ll d[5005];
// d[L] = 길이가 L인 올바른 괄호 문자열 갯수
// d[L] = ∑(d[i-2] * d[L-i]), (2 <= i <= L, i는 짝수)

int main() {
    FASTIO;
    d[0] = 1;
    for (int L = 2; L <= 5000; L += 2) {   // L길이
        for (int i = 2; i <= L; i += 2) {  // i위치
            d[L] += (d[i - 2] * d[L - i]);
            d[L] %= MOD;
        }
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << d[n] << endl;
    }

    return 0;
}
