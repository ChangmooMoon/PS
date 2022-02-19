#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n;
string s1, s2;
vector<string> ans;
int d[101][101];

bool solve(int p1, int p2) {
    int& ret = d[p1][p2];
    if (ret != -1) return ret;

    if (p1 < s1.length() && p2 < s2.length() && (s1[p1] == '?' || s1[p1] == s2[p2])) // 일치
        return ret = solve(p1 + 1, p2 + 1);
    if (p1 == s1.length()) return ret = (p2 == s2.length());
    if (s1[p1] == '*') {
        if (solve(p1 + 1, p2) || (p2 < s2.length() && solve(p1, p2 + 1))) return ret = 1;
    }
    return ret = 0;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> s1 >> n;
        for (int i = 0; i < n; ++i) {
            memset(d, -1, sizeof(d));
            cin >> s2;
            if (solve(0, 0) == 1) ans.push_back(s2);
        }
        sort(ans.begin(), ans.end());
        for (string& s : ans) cout << s << endl;
    }

    return 0;
}
