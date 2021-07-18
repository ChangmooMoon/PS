#include <algorithm>
#include <functional>
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
    int zero = 0, one = 0;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == 0)
            ++zero;
        else if (val == 1)
            ++one;
        else if (val > 0)
            plus.push_back(val);
        else
            minus.push_back(val);
    }
    sort(plus.begin(), plus.end(), greater<>());
    sort(minus.begin(), minus.end());

    if (plus.size() % 2 == 1) plus.push_back(1);
    if (minus.size() % 2 == 1) minus.push_back(zero ? 0 : 1);

    int sum = one;
    for (int i = 0; i < plus.size(); i += 2) {
        sum += plus[i] * plus[i + 1];
    }
    for (int i = 0; i < minus.size(); i += 2) {
        sum += minus[i] * minus[i + 1];
    }

    cout << sum;
    return 0;
}
