#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    vector<int> v(2 * n);  // 0~n-1(up), n~2n-1(down)
    vector<bool> check(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> v[i];
    }

    int broken = 0;
    int step = 0;
    while (true) {
        step++;
        rotate(v.rbegin(), v.rbegin() + 1, v.rend());
        rotate(check.rbegin(), check.rbegin() + 1, check.rend());
        if (check[n - 1]) {
            check[n - 1] = false;
        }

        for (int i = n - 2; i >= 0; --i) {
            if (check[i]) {
                if (!check[i + 1] && v[i + 1] > 0) {
                    check[i + 1] = true;
                    check[i] = false;
                    v[i + 1]--;
                    if (!v[i + 1]) broken++;
                }
            }
        }

        if (check[n - 1]) {
            check[n - 1] = false;
        }
        if (v[0] > 0) {
            check[0] = true;
            v[0]--;
            if (!v[0]) broken++;
        }

        if (broken >= k) break;
    }

    cout << step;
    return 0;
}
