#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
string s;
int d[1001];

char prevChar(char ch) {
    if (ch == 'B')
        return 'J';
    else if (ch == 'O')
        return 'B';
    return 'O';
}

int main() {
    FASTIO;
    cin >> n >> s;
    memset(d, -1, sizeof(d));

    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        char cur = s[i];
        char prev = prevChar(s[i]);
        for (int j = 0; j < i; ++j) {
            if (d[j] == -1) continue;
            if (s[j] != prev) continue;
            if (d[i] == -1 || d[i] > d[j] + (i - j) * (i - j)) {
                d[i] = d[j] + (i - j) * (i - j);
            }
        }
    }
    cout << d[n - 1];
    return 0;
}
