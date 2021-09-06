#include <string>
#include <vector>
using namespace std;

// 가장 짧은 문자열의 길이 리턴
// 1~s.length()/2 까지 잘라볼 수 있음

int getCompLen(string s, int n) {  //s를 n 단위로 잘라서 압축,
    int len = s.length();
    int sPos = 0;

    while (1) {
        string cut = s.substr(sPos, n);
        sPos += n;
        if (sPos >= s.length()) break;  // 0 ~ s.length()-1

        int cutCnt = 0;
        while (1) {
            if (cut != s.substr(sPos, n)) break;

            ++cutCnt;
            sPos += n;
        }

        if (cutCnt > 0) {
            len -= n * cutCnt;  // 중복컷 생긴만큼 빼줌
            // 1, 10, 100, 1000 자릿수 카운트
            if (cutCnt < 9)
                len += 1;
            else if (cutCnt < 99)
                len += 2;
            else if (cutCnt < 999)
                len += 3;
            else if (cutCnt >= 1000)
                len += 4;
        }
    }

    return len;
}

int solution(string s) {
    int ans = s.length();

    for (int i = 1; i <= s.length() / 2; ++i) {
        int len = getCompLen(s, i);
        if (len < ans) ans = len;
    }

    return ans;
}
