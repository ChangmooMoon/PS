#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
       int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=0;
        for(int j=1; j<nums.size(); j++)
            if(nums[i] !=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        return i+1;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 2, 2, 3, 3, 3, 4, 4, 4};
    cout << s.removeDuplicates(v) << endl;
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}