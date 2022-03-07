#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--) {
        string s;
        int r = 500, c = 500, d = 0;
        int maxr = 500, minr = 500, maxc = 500, minc = 500;
        cin >> s;
        for (char ch : s) {
            if (ch == 'F') {
                r += dr[d];
                c += dc[d];
            } else if (ch == 'B') {
                r += dr[(d + 2) % 4];
                c += dc[(d + 2) % 4];
            } else if (ch == 'L') {
                d = (d + 3) % 4;
            } else if (ch == 'R') {
                d = (d + 1) % 4;
            }
            maxr = max(maxr, r);
            maxc = max(maxc, c);
            minr = min(minr, r);
            minc = min(minc, c);
        }
        cout << (maxr - minr) * (maxc - minc) << endl;
    }

    return 0;
}
