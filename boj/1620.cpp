#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
unordered_map<string, int> strToInt;
unordered_map<int, string> intToStr;

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        strToInt[s] = i;
        intToStr[i] = s;
    }

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (isalpha(s[0])) {
            cout << strToInt[s] << endl;
        } else {
            cout << intToStr[stoi(s)] << endl;
        }
    }
    return 0;
}
