#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int seq[9], nums[9];
bool check[9];

void go(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; ++i) {
            int nIdx = seq[i];
            cout << nums[nIdx] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check[i]) continue;

        check[i] = true;
        seq[idx] = i;
        go(idx + 1);
        check[i] = false;
    }
}

// N개 자연수 중에서 M개를 고른 수열, 중복 불가
int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    go(0);

    return 0;
}
