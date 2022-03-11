#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
vector<int> v;

void go(int p) {
    if (p == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
        go(p + 1);
        v.pop_back();
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    go(0);
    return 0;
}
