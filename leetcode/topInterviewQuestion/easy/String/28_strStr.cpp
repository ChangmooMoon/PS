#include <iostream>
using namespace std;

class Solution {
   public:
    int strStr2(string haystack, string needle) {
        // Approach 2: Two Pointers: Linear Time Slice
        int L = needle.length(), n = haystack.length();
        if (L == 0) return 0;

        int pn = 0;
        while (pn < n - L + 1) {
            while (pn < n - L + 1 && haystack.at(pn) != needle.at(0)) {
                ++pn;
            }
            int currLen = 0, pL = 0;
            while (pL < L && pn < n && haystack.at(pn) == needle.at(pL)) {
                ++pn;
                ++pL;
                ++currLen;
            }
            if (currLen == L) return pn - L;
            pn = pn - currLen + 1;
        }
        return -1;
    }

    int strStr3(string haystack, string needle) {
        // rabin karf method
    }
};

int main() {
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr2(haystack, needle) << endl;
    return 0;
}
