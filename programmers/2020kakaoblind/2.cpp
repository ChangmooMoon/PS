#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isCorrect(string& s) {
    int open = 0;
    for (char& ch : s) {
        if (ch == '(')
            ++open;
        else
            --open;
        if (open < 0) return false;
    }

    if (open == 0) return true;
    return false;
}

string solution(string p) {  // p는 균형잡힌 괄호 문자열
    if (p == "") return "";

    int pos, open = 0;
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == '(')
            ++open;
        else
            --open;
        if (open == 0) {
            pos = i + 1;
            break;
        }
    }

    string u = p.substr(0, pos);
    string v = p.substr(pos);

    if (isCorrect(u)) return u + solution(v);

    for (char& ch : u) {
        if (ch == '(')
            ch = ')';
        else
            ch = '(';
    }

    return '(' + solution(v) + ')' + u.substr(1, u.size() - 2);
}
