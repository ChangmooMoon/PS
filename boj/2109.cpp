#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, ans = 0;
vector<int> v[10001];  // 남은 기간별 강의페이

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int pay, day;
        cin >> pay >> day;
        v[day].push_back(pay);
    }

    priority_queue<int> pq;
    for (int i = 10000; i > 0; --i) {
        for (int p : v[i]) pq.push(p);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}
