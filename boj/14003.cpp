#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MAX 1000001

// LIS, backtracking
int n, len = 1;
int a[MAX], LIS[MAX], d[MAX];

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    LIS[0] = a[0];
    d[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= LIS[len - 1]) {
            int idx = lower_bound(LIS, LIS + len, a[i]) - LIS;
            LIS[idx] = a[i];
            d[i] = idx + 1;
        } else {
            LIS[len++] = a[i];
            d[i] = len;
        }
    }
    cout << len << endl;

    vector<int> v;
    for (int i = n - 1; i >= 0; --i) {
        if (d[i] == len) {
            v.push_back(a[i]);
            --len;
        }
    }
    reverse(v.begin(), v.end());
    for (int i : v) cout << i << ' ';
    return 0;
}