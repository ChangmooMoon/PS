#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int n;
tuple<int, int, int> a[100001];
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, h, r;
        cin >> l >> h >> r;
        v.push_back({l, h});
        v.push_back({r, -h});
    }

    sort()

    return 0;
}
