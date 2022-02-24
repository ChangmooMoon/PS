#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// kmp

vector<int> makeTable(string p) {
    int m = p.length();
    vector<int> table(m); // fail

    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && p[i] != p[j])
            j = table[j - 1];
        if (p[i] == p[j]) table[i] = ++j;
    }
    return table;
}

bool isMatch(string s, string p) {
    vector<int> table = makeTable(p);
    int n = s.length(), m = p.length();

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j])
            j = table[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                // ans.push_back(i-m+1);
                // j = table[j];
                return true;
            } else
                ++j;
        }
    }
    return false;
}

int main() {
    FASTIO;
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p);

    return 0;
}
