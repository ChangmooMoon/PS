#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 파싱
int main() {
    FASTIO;
    string type, rest;
    cin >> type;
    while (1) {
        cin >> rest;
        string front, var, back;
        int pos = 0;
        while (pos < rest.length() && !isalpha(rest[pos])) {
            front += rest[pos++];
        }
        while (pos < rest.length() && isalpha(rest[pos])) {
            var += rest[pos++];
        }
        while (pos < rest.length()) {
            if (rest[pos] == '[')
                rest[pos] = ']';
            else if (rest[pos] == ']')
                rest[pos] = '[';
            if (rest[pos] == ';' || rest[pos] == ',') break;
            back += rest[pos++];
        }
        reverse(back.begin(), back.end());
        cout << type << front << back << ' ' << var << ';' << endl;
        if (rest.back() == ';') break;
    }
    return 0;
}
