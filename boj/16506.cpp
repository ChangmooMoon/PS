#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

vector<string> op = {"ADD",  "SUB",   "MOV",   "AND",   "OR", "NOT",
                     "MULT", "LSFTL", "LSFTR", "ASFTR", "RL", "RR"};
bool output[16];
int main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        memset(output, 0, sizeof(output));
        string opcode;
        bool cflag = false;
        int d, a, bc;
        cin >> opcode >> d >> a >> bc;
        auto it = find(op.begin(), op.end(), opcode);
        if (it == op.end()) {
            opcode = opcode.substr(0, opcode.length() - 1);
            output[4] = 1;
            it = find(op.begin(), op.end(), opcode);
            cflag = true;
        }
        int n = it - op.begin();
        for (int i = 3; i >= 0; --i) {
            output[i] = n % 2;
            n /= 2;
        }
        for (int i = 8; i >= 6; --i) {
            output[i] = d % 2;
            d /= 2;
        }
        if (opcode != "MOV" || opcode != "NOT") {
            for (int i = 11; i >= 9; --i) {
                output[i] = a % 2;
                a /= 2;
            }
        }
        for (int i = 14 + cflag; i >= 12; --i) {
            output[i] = bc % 2;
            bc /= 2;
        }
        for (int i = 0; i < 16; ++i) {
            cout << output[i];
        }
        cout << endl;
    }
}
