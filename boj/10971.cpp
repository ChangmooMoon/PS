#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// tsp 외판원 문제, 최소비용찾기
int n;
int w[10][10];  // 100만
vector<int> d;
int ans = INF;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        d.push_back(i);
    }

    do {
        int result = 0;
        bool ok = true;

        for (int i = 1; i < n; ++i) {
            // d[i-1] to d[i];
            int r = w[d[i - 1]][d[i]];
            if (r == 0) {
                ok = false;
            } else {
                result += r;
            }
        }

        int last = w[d[n - 1]][d[0]];
        if (ok && last != 0) {
            result += last;
            if (ans > result) ans = result;
        }

    } while (next_permutation(d.begin() + 1, d.end()));

    cout << ans;
    return 0;
}
