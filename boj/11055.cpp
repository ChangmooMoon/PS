#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, a[1005], d[1005]; // d[i] = i번째 원소를 포함하는 LIS의 합
// d[i] = max(d[j] + a[i]), (a[j] < a[i], j < i)
int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    d[0] = a[0];
    for (int i = 1; i < n; ++i) {
        d[i] = a[i];
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) { d[i] = max(d[j] + a[i], d[i]); }
        }
    }

    cout << *max_element(d, d + n);

    return 0;
}