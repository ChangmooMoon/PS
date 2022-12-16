#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int N, t[16], p[16], d[16], ans;

int solve(int day) {
    if (day > N) return 0;

    int &ret = d[day];
    if (ret != -1) return ret;
    if (day + t[day] <= N + 1) ret = solve(day + t[day]) + p[day];
    return ret = max(ret, solve(day + 1));
}

int main() {
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i] >> p[i];
    }
    memset(d, -1, sizeof(d));
    cout << solve(1);
    return 0;
}

// DP방식으로 풀기
// d[i] = i일까지 얻는 최대이익
// d[i] = max(d[i + 1], d[i + t[i]] + p[i])