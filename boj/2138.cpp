#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;

void toggle(vector<int>& v, int idx) {
    for (int i = idx - 1; i <= idx + 1; ++i) {
        if (0 <= i && i < n) v[i] = 1 - v[i];
    }
}

int go(vector<int> v1, vector<int>& v2) {
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (v1[i] != v2[i]) {
            toggle(v1, i + 1);
            cnt++;
        }
    }

    if (v1 == v2) return cnt;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    cin >> s;
    for (int i = 0; i < n; ++i) {
        b[i] = s[i] - '0';
    }

    int t1 = go(a, b);
    toggle(a, 0);
    int t2 = go(a, b);
    if (t2 != -1) t2++;

    if (t1 != -1 && t2 != -1)
        cout << min(t1, t2);
    else
        cout << max(t1, t2);
    return 0;
}
