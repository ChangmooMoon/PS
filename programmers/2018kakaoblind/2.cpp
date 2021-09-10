#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

// j(A,B) = 교집합크기 / 합집합크기
// str길이 1000, 영문글자만 유효, 공백,숫자,특수문자 뺌, 소문자로 변환
int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<string> v1, v2;
    for (int i = 0; i < str1.length() - 1; ++i) {
        char ch1 = str1[i], ch2 = str1[i + 1];
        if (isalpha(ch1) && isalpha(ch2)) {
            string s;
            s += ch1;
            s += ch2;
            v1.push_back(s);
        }
    }
    for (int i = 0; i < str2.length() - 1; ++i) {
        char ch1 = str2[i], ch2 = str2[i + 1];
        if (isalpha(ch1) && isalpha(ch2)) {
            string s;
            s += ch1;
            s += ch2;
            v2.push_back(s);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<string> unionset, interset;
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(unionset));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(interset));

    if (interset.empty() && unionset.empty()) return 65536;
    return 65536 * interset.size() / unionset.size();
}
// j(A,B) = 교집합크기 / 합집합크기