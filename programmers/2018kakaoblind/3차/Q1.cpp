#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, char> umap;

string convertBase(int num, int base) {
    vector<int> v;
    while (1) {
        v.push_back(num % base);
        num /= base;
        if (num == 0) break;
    }
    string ret = "";
    for (int i = v.size() - 1; i >= 0; --i) {
        ret += umap[v[i]];
    }
    return ret;
}

string solution(int n, int t, int m, int p) { // 진법, 미리구할 숫자갯수, 인원, 순서
    for (int i = 0; i < 10; ++i) {
        umap.insert({i, (char)(i + '0')});
    }
    for (int i = 10; i <= 15; ++i) {
        umap.insert({i, (char)('A' + i - 10)});
    }

    string ans = "";
    int targetNum = 0, seqIdx = 0; // 인원m, 순서p
    while (ans.length() < t) {
        string num = convertBase(targetNum, n);
        for (int i = 0; i < num.length(); ++i) {
            if (seqIdx % m == p - 1) { ans += num[i]; }
            ++seqIdx;
        }
        ++targetNum;
    }
    return ans.substr(0, t);
}
