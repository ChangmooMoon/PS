#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, k, s, x, y;  // 시험관200*200, 바이러스번호1000, 시간10000, x,y좌표1~200
int a[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    queue<pair<int, int>> q;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (!a[i][j]) {
                q.push({i, j});
            }
        }
    }
    cin >> s >> k >> y;

    while (q.empty()) {
        }

    return 0;
}
