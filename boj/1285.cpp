#include <iostream>
#include <vector>
using namespace std;

// H앞 T뒤
int n;

char flip(char ch) {
    if (ch == 'H')
        return 'T';
    else
        return 'H';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = n * n;
    for (int state = 0; state < (1 << n); ++state) { // 행 뒤집을지 결정
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                char now = a[i][j];
                if (state & (1 << j)) now = flip(now);
                if (now == 'T') cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ans = min(ans, sum);
    }

    cout << ans;
    return 0;
}
