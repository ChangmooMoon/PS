#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
typedef pair<int, int> pii;

int n, p, d, ans;
vector<pair<int, int>> v; // {day, pay}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());

    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(-v[i].second);
        if (pq.size() > v[i].first) pq.pop();
    }

    while (!pq.empty()) {
        ans += -pq.top();
        pq.pop();
    }

    cout << ans;
    return 0;
}
