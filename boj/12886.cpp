#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int a, b, c, sum;
bool check[1501][1501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;
    sum = a + b + c;
    if (sum % 3 != 0) {
        cout << 0;
        return 0;
    }

    queue<pii> q;
    q.push({a, b});

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        check[x][y] = true;

        int list[3] = {x, y, sum - x - y};
        for (int i = 0; i < 3; ++i) {      // choose the smallest
            for (int j = 0; j < 3; ++j) {  // target
                if (list[i] < list[j]) {
                    int nList[3] = {x, y, sum - x - y};
                    nList[i] += list[i];
                    nList[j] -= list[i];
                                }
            }
        }
    }

    return 0;
}
