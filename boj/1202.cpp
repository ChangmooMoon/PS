#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int capa[300000];              // 가방용량
pair<int, int> jewel[300000];  // 무게, 가격

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int w, p;
        cin >> w >> p;
        jewel[i] = {w, p};
    }
    for (int i = 0; i < k; ++i) {
        cin >> capa[i];
    }

    sort(jewel, jewel + n);
    sort(capa, capa + k);

    priority_queue<int> pq;  // 비싼 보석가격 maxheap
    long long ans = 0;

    int target = 0; // n*k = 900억
    for (int i = 0; i < k; ++i) {
        while (target < n && jewel[target].first <= capa[i]) {
            pq.push(jewel[target].second);
            target++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}
