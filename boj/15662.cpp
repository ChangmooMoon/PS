#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int t, k;
vector<vector<int>> a(1001, vector<int>(8));
bool check[1001];

// <-6,2-> 극이 다르면 반대로 회전
void myRotate(int idx, int r) {  // idx, 시계반시계
    check[idx] = true;
    int left = a[idx][6];
    int right = a[idx][2];
    if (r == 1) {
        rotate(a[idx].rbegin(), a[idx].rbegin() + 1, a[idx].rend());
    } else {
        rotate(a[idx].begin(), a[idx].begin() + 1, a[idx].end());
    }
    if (idx - 1 >= 0 && !check[idx - 1]) {
        if (left != a[idx - 1][2]) myRotate(idx - 1, r * -1);
    }
    if (idx + 1 < t && !check[idx + 1]) {
        if (right != a[idx + 1][6]) myRotate(idx + 1, r * -1);
    }
}

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        memset(check, false, sizeof(check));
        int n, r;
        scanf("%d %d", &n, &r);
        myRotate(n - 1, r);
    }

    int ans = 0;
    for (int i = 0; i < t; ++i) {
        if (a[i][0] == 1) ++ans;
    }
    cout << ans;
    return 0;
}
