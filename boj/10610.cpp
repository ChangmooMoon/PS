#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int sum = 0;
    for (char ch : s) {
        sum += ch - '0';
    }
    sort(s.begin(), s.end(), greater<>());
    if (s[s.length() - 1] == '0' && sum % 3 == 0) {
        cout << s;
    } else
        cout << -1;

    return 0;
}