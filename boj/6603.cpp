#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int k;
vector<int> v, result;

void go(int idx, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; ++i) {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }
    if (idx == k) return;

    result.push_back(v[idx]);
    go(idx + 1, cnt + 1);
    result.pop_back();
    go(idx + 1, cnt);
}

int main() {
    FASTIO;
    while (1) {
        cin >> k;
        if (k == 0) break;
        v.resize(k);
        for (int i = 0; i < k; ++i) {
            cin >> v[i];
        }
        go(0, 0);  // idx, cnt
        cout << endl;
    }

    return 0;
}
