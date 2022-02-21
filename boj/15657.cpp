#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[8];
vector<int> v;

void dfs(int idx) {
    if (v.size() == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (v.empty() || *v.rbegin() <= a[i]) {
            v.push_back(a[i]);
            dfs(i + 1);
            v.pop_back();
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    dfs(0);
    return 0;
}