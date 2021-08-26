#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 붙여진 넓이의 최대값
int main() {
    FASTIO;
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i] >> c[i];
    }
    // n^2 * 2^2 * 2
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int r1 = r[i], c1 = c[i];
        for (int j = i + 1; j < n; ++j) {
            int r2 = r[j], c2 = c[j];

            for (int rot1 = 0; rot1 < 2; ++rot1) {
                for (int rot2 = 0; rot2 < 2; ++rot2) {
                    if (r1 + r2 <= h && max(c1, c2) <= w) {
                        int tmp = r1 * c1 + r2 * c2;
                        if (ans < tmp) ans = tmp;
                    }

                    if (max(r1, r2) <= h && c1 + c2 <= w) {
                        int tmp = r1 * c1 + r2 * c2;
                        if (ans < tmp) ans = tmp;
                    }

                    swap(r2, c2);
                }
                swap(r1, c1);
            }
        }
    }

    cout << ans;
    return 0;
}
