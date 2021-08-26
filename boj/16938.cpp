#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, l, r, x;
int a[15];
bool check[15];
//브루트포스
int go(int idx) {  // 선택할지 말지 결정
    if (idx == n) {
        int cnt = 0, sum = 0, mx = -1, mn = -1;

        for (int i = 0; i < n; ++i) {
            if (!check[i]) continue;

            sum += a[i];
            ++cnt;
            if (mx == -1 || mx < a[i]) mx = a[i];
            if (mn == -1 || mn > a[i]) mn = a[i];
        }

        if (cnt >= 2 && l <= sum && sum <= r && mx - mn >= x)
            return 1;
        else
            return 0;
    }

    check[idx] = true;
    int cnt1 = go(idx + 1);
    check[idx] = false;
    int cnt2 = go(idx + 1);
    return cnt1 + cnt2;
}

int main() {
    FASTIO;
    cin >> n >> l >> r >> x;  // 난이도합 [l,r], 최대최소 차이 >= x
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << go(0);
    return 0;
}
