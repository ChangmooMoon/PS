#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int t;
bool visit[10001];

string solve(int from, int to) {
    string ret;

    memset(visit, false, sizeof(visit));
    queue<pair<int, string>> q;
    q.push({from, ""});
    visit[from] = true;

    while (!q.empty()) {
        int n;
        string s;
        tie(n, s) = q.front();
        q.pop();
        if (n == to) {
            ret = s;
            break;
        }
        visit[n] = true;

        int Dn, Sn, Ln, Rn;

        Dn = (n * 2) % 10000;
        if (!visit[Dn]) {
            visit[Dn] = true;
            q.push({Dn, s + 'D'});
        }

        Sn = n == 0 ? 9999 : n - 1;
        if (!visit[Sn]) {
            visit[Sn] = true;
            q.push({Sn, s + 'S'});
        }

        Ln = (n % 1000) * 10 + n / 1000;
        if (!visit[Ln]) {
            visit[Ln] = true;
            q.push({Ln, s + 'L'});
        }

        Rn = n / 10 + (n % 10) * 1000;
        if (!visit[Rn]) {
            visit[Rn] = true;
            q.push({Rn, s + 'R'});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        int from, to;
        cin >> from >> to;
        cout << solve(from, to) << '\n';
    }

    return 0;
}
