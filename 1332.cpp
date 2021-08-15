#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f;

int n, v, mn, mx;
int p[10001];
int dp[10001][2];  // 0: 푸는경우, 1: 안푸는경우 // 문제푸는 최소값

int main() {
    FASTIO;
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    mn = mx = p[1];
    dp[1][0] = 1, dp[1][1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][0], d[i - 1][0]) + 1;
        dp[i][1] = dp[i - 1][1];
    }

    return 0;
}
