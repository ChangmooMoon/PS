#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 파싱

int main() {
    FASTIO;
    string type, rest;
    cin >> type;
    while (1) {
        cin >> rest;
        string var, special;
        for (char ch : rest) {
            if (ch == ',' || ch == ';') break;
            if (isalpha(ch))
                var += ch;
            else
                special += ch;
        }
        reverse(special.begin(), special.end());
        for (char &ch : special) {
            if (ch == '[')
                ch = ']';
            else if (ch == ']')
                ch = '[';
        }
        cout << type << special << ' ' << var << ';' << endl;

        if (rest.back() == ';') break;
    }
    return 0;
}
