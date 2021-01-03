#include <iostream>
using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string curr, tmp = countAndSay(n - 1);
        int count = 1;
        char c = tmp[0];  // 1글자씩 읽기

        for (int i = 0; i < tmp.length(); ++i) {
            if (tmp[i] == c)
                count++;
            else {
                curr += to_string(count);
                curr.push_back(c);
                c = tmp[i];
                count = 1;
            }
        }
        curr += to_string(count);
        curr.push_back(c);
        return curr;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(1) << endl;  // "1"
    cout << s.countAndSay(2) << endl;  // "11"  say 1 => "11"
    cout << s.countAndSay(3) << endl;  // "21" say 11 => "21"
    cout << s.countAndSay(4) << endl;  // "1211" say "21" => "1211"
    cout << s.countAndSay(5) << endl;  // say "1211" => "111221"
}