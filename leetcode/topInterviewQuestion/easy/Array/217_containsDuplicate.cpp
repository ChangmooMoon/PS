#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            if (!s.insert(i).second) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 1};
    cout << s.containsDuplicate(v) << endl;
    return 0;
}