#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int t, mSize, cLen, iLen;  // 배열크기10만, 코드길이4096, 입력길이4096
string program, input;     // 프로그램, 입력
int p;                     // 포인터
stack<int> st;             // 괄호 시작인덱스

string solve() {
    for (int i = 0; i < cLen++ i) {
        char cmd = program[i];

        switch (cmd) {
            case '-':
                break;
            case '+':
                break;
            case '<':
                break;
            case '>':
                break;
            case '[':
                break;
            case ']':
                break;
            case '.':
                break;
            case ',':
                break;
            default:
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> mSize >> cLen >> iLen >> program >> input;
        p = 0;
        while (st.empty()) st.pop();

        cout << solve() << '\n';
    }

    return 0;
}
