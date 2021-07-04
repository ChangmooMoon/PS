#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#define ll long long
using namespace std;

ll s, t;

void solve(int n, int m) {
    unordered_set<ll> check;
    queue<pair<ll, string>> q;
    q.push({s, ""});
    check.insert(s);

    while (!q.empty()) {
        ll x;
        string str;
        tie(x, str) = q.front();
        q.pop();

        if (x == t) {
            if (str.length() == 0) str = "0";
            cout << str;
            return;
        }

        if (0 <= x * x && x * x <= 1e9 && check.count(x * x) == 0) {
            q.push({x * x, str + '*'});
            check.insert(x * x);
        }
        if (0 <= x + x && x + x <= 1e9 && check.count(x + x) == 0) {
            q.push({x + x, str + '+'});
            check.insert(x + x);
        }
        if (check.count(0) == 0) {
            q.push({0, str + '-'});
            check.insert(0);
        }
        if (x != 0 && check.count(1) == 0) {
            q.push({1, str + '/'});
            check.insert(1);
        }
    }

    cout << -1;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s >> t;
    solve(s, t);

    return 0;
}
