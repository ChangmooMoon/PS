#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int tp, st, ed, up, dn;
int d[1000001];

bool check(int pos) {
    if (1 > pos || tp < pos) return false;
    if (d[pos] != -1) return false;
    return true;
}

int bfs(int s) {
    queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int now = q.front();
        if (now == ed) return d[now];
        q.pop();

        int next = now + up;
        if (check(next)) {
            q.push(next);
            d[next] = d[now] + 1;
        }

        next = now - dn;
        if (check(next)) {
            q.push(next);
            d[next] = d[now] + 1;
        }
    }

    return -1;
}

int main() {
    FASTIO;
    cin >> tp >> st >> ed >> up >> dn;
    memset(d, -1, sizeof(d));
    int res = bfs(st);
    if (res == -1)
        cout << "use the stairs";
    else
        cout << res;

    return 0;
}
