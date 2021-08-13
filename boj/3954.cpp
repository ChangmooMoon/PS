#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t;           // 20
int sm, sc, si;  // 메모리크기10만, 코드크기2^12, 입력크기2^12
string program, input;

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        cin >> sm >> sc >> si >> program >> input;
    }

    return 0;
}
