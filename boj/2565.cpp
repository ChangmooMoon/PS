#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// LIS
int n;
pair<int, int> a[101];
int d[101];

int main() { // 없애야 하는 전깃줄의 최소갯수
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int from, to;
        cin >> from >> to;
        a[i] = {from, to};
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        d[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i].second > a[j].second) { d[i] = max(d[i], d[j] + 1); }
        }
    }

    cout << n - *max_element(d + 1, d + n + 1);
    return 0;
}
