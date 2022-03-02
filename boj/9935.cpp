#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s, p, ans;

int main() {
    FASTIO;
    cin >> s >> p;
    int len = p.length();
    for (char ch : s) {
        ans.push_back(ch);
        if (ans.size() >= len && ans.substr(ans.size() - len, len) == p) {
            for (int j = 0; j < len; ++j)
                ans.pop_back();
        }
    }
    if (ans.empty()) ans = "FRULA";
    cout << ans;
    return 0;
}
