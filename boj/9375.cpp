#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<string, int> umap;
        for (int i = 0; i < n; ++i) {
            string s, type;
            cin >> s >> type;
            ++umap[type];
        }

        long long ans = 1;
        for (auto &[k, v] : umap) {
            ans *= (long long)v + 1;
        }
        cout << ans - 1 << endl;
    }

    return 0;
}
