#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int bSearch(int s, int e) {
    if (s > e) return -1;
    int m = (s + e) / 2;
    if (v[m] == m)
        return m;
    else if (v[m] < m)
        return bSearch(m + 1, e);
    else
        return bSearch(s, m - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << bSearch(0, n - 1);
    return 0;
}

//  0   1 2 3 4
// -15 -6 1 3 7
// 1. s=0, e=4 m=2
// 2. s=3, e=4, m=3