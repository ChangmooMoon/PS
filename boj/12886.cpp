#include <iostream>
#include <queue>
#include <tuple>
#define pii pair<int, int>
using namespace std;

int a, b, c, sum;
bool check[1501][1501];

int bfs() {
    int ret = 0;
    queue<pii> q;
    q.push({a, b});
    check[a][b] = true;

    while (!q.empty()) {
        int x, y, z;
        tie(x, y) = q.front();
        q.pop();
        z = sum - x - y;
        if (x == y && y == z) {
            ret = 1;
            break;
        }

        int list[3] = {x, y, z};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (list[i] < list[j]) {  // X < Y
                    int nList[3] = {x, y, z};
                    nList[i] += list[i];
                    nList[j] -= list[i];

                    int nx = nList[0];
                    int ny = nList[1];
                    if (check[nx][ny]) continue;
                    q.push({nx, ny});
                    check[nx][ny] = true;
                }
            }
        }
    }

    return ret;
}

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

    cout << bfs();
    return 0;
}
