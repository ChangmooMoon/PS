#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int go(string& s, int idx, char last) {
    if (idx == s.length()) return 1;

    char start = s[idx] == 'c' ? 'a' : '0';
    char end = s[idx] == 'c' ? 'z' : '9';
    int ans = 0;

    for (char i = start; i <= end; ++i) {
        if (i != last) {
            ans += go(s, idx + 1, i);
        }
    }

    return ans;
}

int main() {
    FASTIO;

    string s;
    cin >> s;  // 26^4

    cout << go(s, 0, ' ');

    return 0;
}
