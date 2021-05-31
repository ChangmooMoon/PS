#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<char> alpha(256);

int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
    int m = letters.size();
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        alpha[letters[i]] = d[i];
    }

    for (string& s : a) {
        int now = 0;
        for (char ch : s) {
            now = now * 10 + alpha[ch];
        }
        sum += now;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<string> a(n);
    vector<char> letters;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (char ch : a[i]) {
            letters.push_back(ch);
        }
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    int m = letters.size();
    vector<int> d;
    for (int i = 9; i > 9 - m; --i) {
        d.push_back(i);
    }
    sort(d.begin(), d.end());

    int ans = 0;
    do {
        int now = calc(a, letters, d);
        ans = max(ans, now);
    } while (next_permutation(d.begin(), d.end()));

    cout << ans;

    return 0;
}
