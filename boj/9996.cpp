#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
string p, s;
regex re;

int main() {
    FASTIO;
    cin >> n >> p;
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == '*') {
            re.assign(p.substr(0, i) + ".*" + p.substr(i + 1));
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (regex_match(s, re))
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }

    return 0;
}
