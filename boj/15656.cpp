#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int a[8], nums[8];

void go(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; ++i) {
            cout << nums[a[i]] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        a[idx] = i;
        go(idx + 1);
    }
}

// N개의 자연수 중에 M개를 고른 수열, 선택중복가능
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
