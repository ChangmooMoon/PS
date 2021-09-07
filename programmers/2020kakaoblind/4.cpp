#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(const string& a, const string& b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

// 찾고자 하는 키워드queires 10만, 모든 단어 담긴 배열 words 10만
vector<int> solution(vector<string> words, vector<string> queries) {
    int N = queries.size();
    vector<int> answer(N);

    vector<string> rwords = words;
    sort(words.begin(), words.end(), cmp);
    for (string& s : rwords) {
        reverse(s.begin(), s.end());
    }
    sort(rwords.begin(), rwords.end(), cmp);

    // words {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    // queries {"pro?", "????o", "fr???", "fro??", "fro???"}

    for (int i = 0; i < queries.size(); ++i) {  // ? 63, a 97 z 122
        if (queries[i][0] != '?') {             // ?로 끝남
            string lquery = queries[i], rquery = queries[i];
            for (char& ch : lquery) {
                if (ch == '?') ch = 'a';
            }  // fraaa
            for (char& ch : rquery) {
                if (ch == '?') ch = 'z';
            }  // frzzz

            // 오름차순 정렬에서 특정범위 속하는 숫자가 몇개 있는지, k상한 - k하한 = k갯수
            auto lIt = lower_bound(words.begin(), words.end(), lquery, cmp);  // fraaa 하한위치
            auto rIt = upper_bound(words.begin(), words.end(), rquery, cmp);  // frzzz 상한위치
            answer[i] = rIt - lIt;
        } else {  // ?로 시작함
            reverse(queries[i].begin(), queries[i].end());
            string lquery = queries[i], rquery = queries[i];
            for (char& ch : lquery) {
                if (ch == '?') ch = 'a';
            }  // aaaao -> oaaaa
            for (char& ch : rquery) {
                if (ch == '?') ch = 'z';
            }  // zzzzo -> ozzzz

            auto lIt = lower_bound(rwords.begin(), rwords.end(), lquery, cmp);
            auto rIt = upper_bound(rwords.begin(), rwords.end(), rquery, cmp);
            answer[i] = rIt - lIt;
        }
    }

    return answer;
}
