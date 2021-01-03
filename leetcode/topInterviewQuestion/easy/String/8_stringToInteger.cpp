#include <cctype>   // isspace(), isdigit()
#include <climits>  // INT_MAX, INT_MIN
#include <iostream>
using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        int i = 0, sign = 1, n = 0;
        if (s.length() == 0) {
            return 0;
        }
        while (isspace(s[i])) {
            ++i;
        }
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        while (isdigit(s[i])) {
            if (n > INT_MAX / 10 || (n == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            n = n * 10 + (s[i++] - '0');
        }
        return sign * n;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("    -42") << endl;
    cout << s.myAtoi("4193 with words") << endl;
    cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("-91283472332") << endl;  // -1089159116
}