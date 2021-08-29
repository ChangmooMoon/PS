#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>
#define INF 987654321
using namespace std;

int n, k;
int ans = INF;

int main() {
    cin >> n >> k;
    vector<tuple<int, int, int>> v;  // r, c, color
    vector<int> perm;

    for (int i = 0; i < n; ++i) {
        int c, r, color;
        cin >> c >> r >> color;
        v.push_back({r, c, color});
    }

    int len = v.size();
    perm.resize(len);
    perm[len - 2] = perm[len - 1] = 1;

    do {
        vector<tuple<int, int, int>> point;  // 꼭지점 N개 중에서 2개를 고름 // 100C2 = 4950
        unordered_set<int> s;                // 이 안에 point의 컬러 2개 빼고 color가 k-2개 있으면 됨
        for (int i = 0; i < len; ++i) {
            if (perm[i]) point.push_back(v[i]);
        }

        // 1. 그 두 꼭지점이 color가 다름.
        const auto& [r1, c1, color1] = point[0];
        const auto& [r2, c2, color2] = point[1];
        if (color1 == color2) continue;

        // 2. 그 안에 color가 다른 꼭지점이 k-2개가 딱 있으면 성립. 그 중 제일 작은 넓이
        int top, bottom, left, right;
        top = min(r1, r2);
        bottom = max(r1, r2);
        left = min(c1, c2);
        right = max(c1, c2);

        unordered_set<int> uset;
        for (int i = 0; i < len; ++i) {
            if (perm[i]) continue;

            const auto& [r3, c3, color3] = v[i];
            if (top <= r3 && r3 <= bottom && left <= c3 && c3 <= right && color3 != color1 && color3 != color2) {
                uset.insert(color3);
            }
        }

        if (uset.size() == k - 2) {
            ans = min(ans, (right - left) * (bottom - top));
        }

    } while (next_permutation(perm.begin(), perm.end()));

    if (ans == INF) {
        cout << 0;
    } else
        cout << ans;
    return 0;
}
