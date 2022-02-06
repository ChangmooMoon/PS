#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int a[9], nums[9];
int n, m;

void go(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout << nums[a[i]] << ' ';
        }
        cout << endl;
        return;
    }
    if (idx >= n) return;

    a[cnt] = idx;
    go(idx + 1, cnt + 1);

    a[cnt] = 0;
    go(idx + 1, cnt);
}

// N개의 자연수 중에서 M개를 고른 수열, 중복불가
int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + n);
    go(0, 0);

    return 0;
}
