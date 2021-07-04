#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int t;
bool prime[10001];
int dist[10001];

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int change(int n, int idx, int digit) {
    if (idx == 0 && digit == 0) return -1;

    string s = to_string(n);
    s[idx] = digit + '0';
    return stoi(s);
}

int go(int u, int v) {
    memset(dist, -1, sizeof(dist));

    dist[u] = 0;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j <= 9; ++j) {
                int next = change(now, i, j);
                if (next == -1) continue;

                if (prime[next] && dist[next] == -1) {
                    q.push(next);
                    dist[next] = dist[now] + 1;
                }
            }
        }
    }

    return dist[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i < 10000; ++i) {
        prime[i] = isPrime(i);
    }

    cin >> t;
    while (t--) {
        int from, to;
        cin >> from >> to;

        int num = go(from, to);
        if (num == -1)
            cout << "Impossible" << '\n';
        else
            cout << num << '\n';
    }

    return 0;
}
