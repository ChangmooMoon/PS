#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        vector<int> nDigits(digits.size() + 1);
        nDigits[0] = 1;
        return nDigits;
    }
};

int main() {
    Solution s;
    vector<int> v{9, 9, 9};
    vector<int> v2;
    v2 = s.plusOne(v);

    for (int i : v2) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}