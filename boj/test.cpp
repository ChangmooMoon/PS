#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
    // 0 | 0 = 0, 0|1 = 1, 1|0 = 1, 1|1 = 1 둘다 0이여야
    // cout << (15 | 12);  // 1111 | 1100 = 1111

    // multiset<int> mset;
    // mset.insert(11);
    // mset.insert(6);
    // mset.insert(4);
    // mset.insert(15);
    // mset.insert(1);
    // mset.insert(5);

    // cout << *mset.begin() << endl;   // 1
    // cout << *mset.rbegin() << endl;  // 15
    int ans = 0;
    ans += 5 / 6;
    cout << ans;
}
