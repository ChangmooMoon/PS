#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;  // 나무수100만, 필요한 나무의 길이20억
vector<int> v;

// 최소 m미터의 나무를 가져가기 위한 절단기높이 최대값
bool check(long long mid) {
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] - mid > 0) {
            cnt += v[i] - mid;
        }
    }

    return cnt >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long l = 0, r = *max_element(v.begin(), v.end());
    long long ans = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
