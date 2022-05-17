#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s;
int a[26];

int main() {
    FASTIO;
    cin >> s;
    for (char ch : s) {
        ++a[ch - 'a'];
    }
    for (int n : a) {
        cout << n << ' ';
    }
    return 0;
}
