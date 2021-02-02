#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, c;       // n200000, c200000,
vector<int> v;  // v[i]1,000,000,000

bool go(int maxDist) {
    int count = 1;
    int now = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] - now >= maxDist) {
            count++;
            now = v[i];
        }
    }
    return count >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> c;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int left = 1;
    int right = 1'000'000'000;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (go(mid))  // 최대거리가 mid일때 설치했을때 c개만큼 설치
            left = mid;
        else
            right = mid;
    }
    cout << left;
    return 0;
}
