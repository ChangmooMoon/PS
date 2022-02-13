#include <iostream>
#include <string>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 가로3 세로 5
int num[10][5][3] = {
    {{0, 1, 0}, {1, 0, 1}, {0, 0, 0}, {1, 0, 1}, {0, 1, 0}},
    {{0, 0, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 1}, {0, 0, 0}},
    {{0, 1, 0}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 0}},
    {{0, 1, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, 1}, {0, 1, 0}},
    {{0, 0, 0}, {1, 0, 1}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}},
    {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 1, 0}},
    {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}, {1, 0, 1}, {0, 1, 0}},
    {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 1}, {0, 0, 0}},
    {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}, {1, 0, 1}, {0, 1, 0}},
    {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}, {0, 0, 1}, {0, 1, 0}},
};

int s;
string str;
int len;

int main() {
    FASTIO;
    cin >> s >> str;
    len = str.length();

    for (int r = 0; r < 5; ++r) {
        if (r % 2) {  // 1,3... 세로
            for (int k = 0; k < s; ++k) {
                for (int i = 0; i < len; ++i) {
                    int cur = str[i] - '0';
                    cout << (num[cur][r][0] == 1 ? '|' : ' ');
                    for (int j = 0; j < s; ++j) cout << ' ';
                    cout << (num[cur][r][2] == 1 ? '|' : ' ');
                    cout << ' ';
                }
                cout << endl;
            }
        } else {  // 2, 4... 가로
            for (int i = 0; i < len; ++i) {
                cout << ' ';
                int cur = str[i] - '0';
                for (int j = 0; j < s; ++j) {
                    cout << (num[cur][r][1] == 1 ? '-' : ' ');
                }
                cout << ' ';
                cout << (i == len - 1 ? endl : ' ');
            }
        }
    }

    return 0;
}
