#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s, s2;
int main() {
    FASTIO;
    cin >> s;
    int len = s.length();
    if (len % 3 == 1)
        s = "00" + s;
    else if (len % 3 == 2)
        s = '0' + s;

    for (int i = 0; i < s.length(); i += 3) {
        cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + s[i + 2] - '0';
    }

    return 0;
}
