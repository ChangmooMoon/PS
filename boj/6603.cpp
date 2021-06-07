#include <iostream>
#include <vector>
using namespace std;

vector<int> combi;                           // 조합
void go(vector<int>& a, int idx, int cnt) {  // a.length(s개) 중에 6개 고르기, cnt 고른갯수
    if (cnt == 6) {
        for (int n : combi) cout << n << ' ';
        cout << '\n';
        return;
    }
    if (idx == a.size()) return;

    combi.push_back(a[idx]); // a[idx] 선택
    go(a, idx + 1, cnt + 1);
    combi.pop_back(); // a[idx] 선택 안함
    go(a, idx + 1, cnt);
}

// 2^12 = 4096
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        int k;
        cin >> k;
        if (k == 0) break;

        vector<int> s(k);
        for (int i = 0; i < k; ++i)
            cin >> s[i];

        go(s, 0, 0);
        cout << '\n';
    }

    return 0;
}
