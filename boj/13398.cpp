#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> d1(n);  // i에서 끝나는 연속합
    vector<int> d2(n);  // i에서 시작하는 연속합

    for (int i = 0; i < n; i++) {
        d1[i] = a[i];
        if (i == 0) continue;

        int pSum = d1[i - 1] + a[i];
        d1[i] = max(d1[i], d1[i - 1] + a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        d2[i] = a[i];
        if (i == n - 1) continue;
        d2[i] = max(d2[i], d2[i + 1] + a[i]);
    }

    int big = d1[0];
    for (int i = 1; i < n; i++) {
        big = max(big, d1[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        big = max(big, d1[i - 1] + d2[i + 1]);
    }

    cout << big;
    return 0;
}
