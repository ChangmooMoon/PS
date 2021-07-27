#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;  // 아이 20억, 놀이기구 1만
int a[10000];   // 운행시간 1~30

int solve() {
    if (n <= m) return n;  // 놀이기구가 더 많으면 n

    long long l = 0, r = 6000000000, cnt;
    while (l <= r) { // 
        long long mid = l + (r - l) / 2;
        cnt = mid;

        for (int i = 0; i < m; ++i) {
            cnt += mid / a[i];
        }
        if(cnt >= n)
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    cout << solve();
    return 0;
}

// 1,2,3,4,5 -> 모두 같이 타는 텀 0, 30, 60초
