#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, a[8];
vector<int> v;

void go(int idx, int p) {
    if (p == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < n; ++i) {
        v.push_back(a[i]);
        go(i, p + 1);
        v.pop_back();
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    go(0, 0);
    return 0;
}
