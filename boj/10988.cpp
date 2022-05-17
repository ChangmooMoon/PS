#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s, rs;

int main() {
    FASTIO;
    cin >> s;
    rs = s;
    reverse(rs.begin(), rs.end());
    if (s == rs)
        cout << 1;
    else
        cout << 0;
    return 0;
}
