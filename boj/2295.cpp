#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// a[i] + a[j] + a[k] = a[l]
// v[i] + a[k] = a[l]
// a[l] - a[k] = v[i]
int n, a[1001], ans = -1;
vector<int> v; // a[i] + a[j]

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            v.push_back(a[i] + a[j]);
        }
    }
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (binary_search(v.begin(), v.end(), a[i] - a[j])) {
                cout << a[i];
                return 0;
            }
        }
    }
    return 0;
}
