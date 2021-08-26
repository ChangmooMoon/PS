#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int main() {
    FASTIO;
    string s;
    cin >> s;

    int ans = 1;
    for (int i = 0; i < s.length(); ++i) {
        int cnt = s[i] == 'c' ? 26 : 10;
        if (i > 0 && s[i] == s[i - 1]) {
            --cnt;
        }

        ans *= cnt;
    }

    cout << ans;
    return 0;
}
