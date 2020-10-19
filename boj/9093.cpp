#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string str;
        getline(cin, str);
        str += '\n';

        stack<char> s;
        for (char ch : str) {
            if (ch == ' ' || ch == '\n') {
                while (!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << ch;
            } else {
                s.push(ch);
            }
        }
    }

    return 0;
}
