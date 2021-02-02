#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int min = pq.top();
        pq.pop();
        min += pq.top();
        pq.pop();
        ans += min;
        pq.push(min);
    }

    cout << ans;
    return 0;
}
