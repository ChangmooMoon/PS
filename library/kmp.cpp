#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s, p;

vector<int> makeTable(string p) {
    int m = p.length();
    vector<int> fail(m);
    fail[0] = 0;
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && p[i] != p[j]) {
            j = fail[j - 1];
        }
        if (p[i] == p[j]) {
            fail[i] = j + 1;
            ++j;
        } else
            fail[i] = 0;
    }
    return fail;
}

vector<int> kmp(string s, string p) {
    vector<int> fail = makeTable(p);
    vector<int> ans;
    int n = s.length(), m = p.length();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j]) {
            j = fail[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = fail[j];
            } else {
                ++j;
            }
        }
    }
    return ans;
}

int main() {
    FASTIO;
    cin >> s >> p;
    vector<int> ans = kmp(s, p);
    for (int i : ans) {
        cout << i << ' ';
    }
    return 0;
}
