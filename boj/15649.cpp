#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
bool check[9];
vector<int> v;

void go(int p) { // nPm
    if (p == m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(i);
        go(p + 1);
        check[i] = false;
        v.pop_back();
    }
}

int main() {
    FASTIO;
    cin >> n >> m;
    go(0);
    return 0;
}
