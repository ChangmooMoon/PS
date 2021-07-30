#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string s, string ans) {
    if (s.empty()) {
        cout << ans << ' ';
        return;
    }
    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        string l = s.substr(0, i);
        string r = s.substr(i + 1);
        string rest = l + r;
        permute(rest, ans + ch);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "ABC", ans = "";
    permute(s, ans);
    return 0;
}
