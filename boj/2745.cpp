#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s;
int b;

int main() {
    FASTIO;
    cin >> s >> b;
    int ans = 0;
    for (char ch : s) {
        ans *= b;
        if (ch <= '9')
            ans += ch - '0';
        else
            ans += ch - 'A' + 10;
    }
    cout << ans;
    return 0;
}
