#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 회의실 배정
int n;
vector<pair<int, int>> v;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        v.push_back({to, from});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        const auto &[to, from] = v[i];
        cout << from << ' ' << to << endl;
    }

    int cnt = 0, e = 0;
    for (int i = 0; i < n; ++i) {
        if (e <= v[i].second) {
            ++cnt;
            e = v[i].first;
        }
    }

    cout << cnt;
    return 0;
}
