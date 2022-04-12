#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// stable sort 안정정렬, 문자열 파싱
pair<string, int> parse(string s) { // head, number
    string head, number;
    bool numFlag = false;
    int p = 0;
    while (p != s.length()) {
        if (!numFlag) {
            if (!isdigit(s[p])) {
                head += tolower(s[p]);
            } else {
                numFlag = true;
                continue;
            }
        } else {
            if (isdigit(s[p])) {
                number += s[p];
            } else
                break;
        }
        ++p;
    }

    return {head, stoi(number)};
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), [](string a, string b) { return parse(a) < parse(b); });

    return files;
}
