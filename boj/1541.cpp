#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 수식 변환 문제
// -가 나올때 그 뒤의 +값들을 전부 묶으면 최소가 됨
char op[2] = {'+', '-'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    vector<int> digit;
    vector<int> op;
    bool minus = false;

    int num = 0;
    op.push_back(1);
    for (char ch : s) {
        if (ch == '+' || ch == '-') {
            if (ch == '+')
                op.push_back(1);
            else
                op.push_back(-1);

            digit.push_back(num);
            num = 0;
        } else {
            num = num * 10 + (ch - '0');
        }
    }
    digit.push_back(num);

    int ans = 0;
    for (int i = 0; i < digit.size(); ++i) {
        if (op[i] == -1) minus = true;

        if (minus)
            ans -= digit[i];
        else
            ans += digit[i];
    }

    cout << ans;
    return 0;
}
