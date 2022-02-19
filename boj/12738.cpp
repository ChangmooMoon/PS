#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
vector<int> v;

// LIS NlogN 이분탐색
int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int n;
        cin >> n;
        int idx = lower_bound(v.begin(), v.end(), n) - v.begin();
        if (idx == v.size())
            v.push_back(n);
        else
            v[idx] = n;
    }
    cout << v.size();

    return 0;
}