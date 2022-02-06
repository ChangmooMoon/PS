#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[11], op[4];
vector<int> ans;

void go(int idx, int result, int pl, int mi, int mul, int div) {
    if (idx == n) {
        ans.push_back(result);
        return;
    }

    if (pl)
        go(idx + 1, result + a[idx], pl - 1, mi, mul, div);
    if (mi)
        go(idx + 1, result - a[idx], pl, mi - 1, mul, div);
    if (mul)
        go(idx + 1, result * a[idx], pl, mi, mul - 1, div);
    if (div)
        go(idx + 1, result / a[idx], pl, mi, mul, div - 1);
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }

    go(1, a[0], op[0], op[1], op[2], op[3]);
    sort(ans.begin(), ans.end());
    cout << *ans.rbegin() << endl
         << *ans.begin();
    return 0;
}
