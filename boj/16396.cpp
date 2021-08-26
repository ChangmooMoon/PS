#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
pair<int, ll> a[100];  // 3의 갯수, 실제수

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll sum;
        cin >> sum;
        a[i].second = sum;

        while (sum % 3 == 0) {
            sum /= 3;
            a[i].first += 1;
        }
        a[i].first = -a[i].first;
    }

    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        cout << a[i].second << ' ';
    }

    return 0;
}
