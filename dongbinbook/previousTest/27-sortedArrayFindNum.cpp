#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, t;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int ans = upper_bound(v.begin(), v.end(), t) - lower_bound(v.begin(), v.end(), t);
    if (!ans)
        cout << -1;
    else
        cout << ans;

    return 0;
}
