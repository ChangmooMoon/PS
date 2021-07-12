#include <iostream>
#include <vector>
using namespace std;
// LIS 문제

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // NLogN 이분탐색
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);
        if (it == a.end())
            a.push_back(num);
        else
            *it = num;

        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    cout << a.size();
    return 0;
}
