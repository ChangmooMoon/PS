#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    cin.ignore();
    string s;
    string s2;
    getline(cin, s);
    getline(cin, s2);
    cout << s[0] << s[1] << s[2] << s[3] << endl;
    cout << s2[0] << s2[1] << s2[2] << s2[3] << endl;
    return 0;
}
