#include <algorithm>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

bool cmp(pii& a, pii& b) {  // 1. 끝 오름차순 2. 시작 오름차순
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    int end = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (end <= v[i].first) {
            cnt++;
            end = v[i].second;
        }
    }

    cout << cnt;
    return 0;
}
