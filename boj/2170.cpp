// 스위핑 알고리즘
#include <iostream>
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;

int n;
pii v[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v, v + n);

    int ans = 0, l = -INF, r = -INF;
    for (int i = 0; i < n; ++i) {
        if (v[i].first < r)
            r = max(r, v[i].second);  // 연장
        else {
            ans += r - l;  // 선 리셋
            l = v[i].first;
            r = v[i].second;
        }
    }
    ans += r - l;
    cout << ans;
    return 0;
}
