#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int a, b;
int ans = -1;

// 순열을 직접 구현함. 복잡도 9!
void permutation(string& s, int depth) {
    if (depth == s.length()) {
        string newStr = "";
        for (int i = 0; i < s.length(); ++i) {
            newStr += s[i];
        }

        if (newStr[0] == '0') return;

        int nn = stoi(newStr);
        if (nn < b && ans < nn) ans = nn;

        return;
    }

    for (int i = depth; i < s.length(); ++i) {
        swap(s[depth], s[i]);
        permutation(s, depth + 1);
        swap(s[depth], s[i]);
    }
}

int go() {
    string sa = to_string(a);
    int len = sa.length();
    permutation(sa, 0);

    return ans;
}

int main() {
    FASTIO;
    cin >> a >> b;
    cout << go();
    return 0;
}
