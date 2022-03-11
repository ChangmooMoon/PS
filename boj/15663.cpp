#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, a[8];
vector<int> v;
bool check[8];
set<vector<int>> s;

void go(int p) {
    if (p == m) {
        s.insert(v);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(a[i]);
        go(p + 1);
        check[i] = false;
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
    go(0);
    for (auto b : s) {
        for (int i : b) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
