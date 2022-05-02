#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> ans;

    vector<string> rwords = words;
    sort(words.begin(), words.end(), cmp);
    for (string &s : rwords) {
        reverse(s.begin(), s.end());
    }
    sort(rwords.begin(), rwords.end(), cmp);

    for (string q : queries) {
        if (q[0] != '?') {
            string l = q, r = q;

            for (char &ch : l) {
                if (ch == '?') ch = 'a';
            }
            for (char &ch : r) {
                if (ch == '?') ch = 'z';
            }

            auto rIt = upper_bound(words.begin(), words.end(), r, cmp);
            auto lIt = lower_bound(words.begin(), words.end(), l, cmp);
            ans.push_back(rIt - lIt);
        } else {
            reverse(q.begin(), q.end());
            string l = q, r = q;

            for (char &ch : l) {
                if (ch == '?') ch = 'a';
            }
            for (char &ch : r) {
                if (ch == '?') ch = 'z';
            }
            auto rIt = upper_bound(rwords.begin(), rwords.end(), r, cmp);
            auto lIt = lower_bound(rwords.begin(), rwords.end(), l, cmp);
            ans.push_back(rIt - lIt);
        }
    }

    return ans;
}
