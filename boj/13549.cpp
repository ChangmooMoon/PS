#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
int d[200005];

int solve(int s, int e) {
    deque<int> dq;
    dq.push_back(s);
    d[s] = 0;

    while (!dq.empty()) {
        int p = dq.front();
        dq.pop_front();

        if (p == e) return d[p];
        if (2 * p <= 100000 && d[2 * p] == -1) {
            dq.push_front(2 * p);
            d[2 * p] = d[p];
        }
        if (p - 1 >= 0 && d[p - 1] == -1) {
            dq.push_back(p - 1);
            d[p - 1] = d[p] + 1;
        }
        if (p + 1 <= 100000 && d[p + 1] == -1) {
            dq.push_back(p + 1);
            d[p + 1] = d[p] + 1;
        }
    }

    return -1;
}

int main() {
    FASTIO;
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    cout << solve(n, m);

    return 0;
}
