#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200000;

int n, k;
int visit[MAX + 1];
int d[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    visit[n] = 1;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        if (0 <= pos - 1 && !visit[pos - 1]) {
            q.push(pos - 1);
            visit[pos - 1] = 1;
            d[pos - 1] = d[pos] + 1;
        }
        if (pos + 1 < MAX && !visit[pos + 1]) {
            q.push(pos + 1);
            visit[pos + 1] = 1;
            d[pos + 1] = d[pos] + 1;
        }
        if (pos * 2 < MAX && !visit[pos * 2]) {
            q.push(pos * 2);
            visit[pos * 2] = 1;
            d[pos * 2] = d[pos] + 1;
        }
    }

    cout << d[k];
    return 0;
}
