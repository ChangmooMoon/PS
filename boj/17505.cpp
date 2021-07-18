#include <iostream>
#include <vector>
using namespace std;

int n;
long long k;  // 반전 갯수 i<j, pi > pj

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    vector<int> v;

    int start = 1, end = n;
    for (int i = 1; i <= n; ++i) {
        if (k < n - i) {
            v.push_back(start);
            ++start;
        } else {
            k -= (n - i);
            v.push_back(end);
            --end;
        }
    }

    if (k > 0 || start <= end)
        cout << -1;
    else {
        for (int i = 0; i < n; ++i)
            cout << v[i] << ' ';
    }
    return 0;
}
