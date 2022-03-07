#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, t, a[100001];

bool bsearch(int t) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (a[mid] < t)
            s = mid + 1;
        else if (a[mid] > t)
            e = mid - 1;
        else
            return true;
    }
    return false;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        cout << bsearch(t) << endl;
    }

    return 0;
}
