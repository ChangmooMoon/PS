#include <iostream>
#include <vector>
using namespace std;

int n, k;  // 보석n개, 가방k개

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int m, v;
        cin >> m >> v;
        v[i] = {m, v};
    }

    return 0;
}
