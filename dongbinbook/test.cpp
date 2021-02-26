#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int solution(string s) {  // 문자열 1000000
    unordered_set<char> cSet;

    for (int i = 0; i < s.length(); ++i) {
        if (!cSet.empty()) {
            if (s[i] == *(cSet.begin())) {
                cSet.erase(cSet.begin());
            } else {
                cSet.insert(s[i]);
            }
        } else {
            cSet.insert(s[i]);
        }
    }

    return cSet.empty() ? 1 : 0;
}

int main() {
    string s = "baabaa";
    solution(s);
    return 0;
}