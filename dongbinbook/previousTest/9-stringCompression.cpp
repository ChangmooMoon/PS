#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 1; i <= s.length / 2; ++i) {
        int pos = 0;
        int cSize = s.length();

        while (1) {
            string cut = s.substr(pos, i);
            pos += i;

            if (pos >= s.length()) {
                break;
            }

            int count = 0;
            while (1) {
                if (cut.compare(s.substr(pos, i)) == 0) {
                    ++count;
                    pos += i;
                } else
                    break
            }
            if (count > 0) {
                len
            }
        }
    }
    return answer;
}