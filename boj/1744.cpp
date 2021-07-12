#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val > 0)
            plus.push_back(val);
        else
            minus.push_back(val);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    int sum = 0;
    for (int i = plus.size() - 1; i >= 0; i -= 2) {  // 1,2,3
        if (i >= 2)
            sum += plus[i] * plus[i - 1];
        else
            sum += plus[i];
    }
    for (int i = 0; i < minus.size(); i += 2) {  // -3 -2 -1
        if (i >= minus.size() - 1)
            sum += minus[i];
        else
            sum += minus[i] * minus[i + 1];
    }

    cout << sum;
    return 0;
}
