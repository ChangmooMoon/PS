#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                return vector<int>{i, it->second};
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{2, 7, 11, 15};
    auto ans = s.twoSum(v, 9);
    for (int i : ans) {
        cout << i << ' ';
    }
    return 0;
}