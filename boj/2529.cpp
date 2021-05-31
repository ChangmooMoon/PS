#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int k;  // 2~9 부등호갯수
bool check(vector<int>& nums, vector<char>& signs) {
    for (int i = 0; i < signs.size(); ++i) {
        if (nums[i] < nums[i + 1] && signs[i] == '<') continue;
        if (nums[i] > nums[i + 1] && signs[i] == '>') continue;
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    vector<char> a(k);
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    vector<int> small(k + 1);
    vector<int> big(k + 1);
    for (int i = 0; i <= k; ++i) {
        small[i] = i;
        big[i] = 9 - i;
    }

    do {
        if (check(small, a)) break;
    } while (next_permutation(small.begin(), small.end()));  // 0123, 0132,...

    do {
        if (check(big, a)) break;
    } while (prev_permutation(big.begin(), big.end()));  // 9876, 9867, ...

    for (int i = 0; i < big.size(); ++i)
        cout << big[i];
    cout << '\n';
    for (int i = 0; i < small.size(); ++i)
        cout << small[i];

    return 0;
}
