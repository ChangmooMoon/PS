#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Man {
    int d, h, line;
    bool isMe;
    bool operator<(const Man& other) const {
        if (d == other.d) {
            if (h == other.h) return line > other.line;
            return h < other.h;
        }
        return d < other.d;
    }
};

int n, m, k, ans;
queue<Man> line[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        int d, h;
        cin >> d >> h;
        line[i % m].push({d, h, i % m, i == k});
    }

    priority_queue<Man> pq;
    for (int i = 0; i < m; ++i) {
        if (line[i].empty()) continue;

        pq.push(line[i].front());
        line[i].pop();
    }

    while (true) {
        Man man = pq.top();
        pq.pop();
        if (man.isMe) break;

        ++ans;
        if (!line[man.line].empty()) {
            pq.push(line[man.line].front());
            line[man.line].pop();
        }
    }

    cout << ans;
    return 0;
}