#include <iostream>
#include <vector>
using namespace std;
// LIS, LDS 문제, 비둘기집

int n, m, k;
vetor<int> v;  // 1~n
int solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        v.push_back (i);
    }

    cout << solve();
    return 0;
}
