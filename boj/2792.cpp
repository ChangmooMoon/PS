#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f
// 이분탐색

int n, m, ans = INF; // 아이수, 색상수
int a[300004];

bool check(int mid) { // mid개씩 나눠주기
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        cnt += a[i] / mid;
        if (a[i] % mid) ++cnt;
    }

    return n >= cnt;
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    int s = 1, e = *max_element(a, a + m);
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        } else
            s = mid + 1;
    }

    cout << ans;
    return 0;
}
