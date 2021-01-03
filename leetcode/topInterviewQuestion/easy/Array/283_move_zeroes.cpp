#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[right++], nums[i]);
            }
        }
    }
};

int main() {
    vector<int> v{0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(v);
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
