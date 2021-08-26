#include <algorithm>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;  // 10만
        cin >> n;
        vector<pii> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());

        int cnt = 1, minimum = v[0].second;
        for (int i = 1; i < n; ++i) {
            if (v[i].second < minimum) {
                minimum = v[i].second;
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
