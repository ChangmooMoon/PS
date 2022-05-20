#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;
unordered_set<int> uset;

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        uset.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            uset.insert(num);
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (uset.find(num) != uset.end())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}
