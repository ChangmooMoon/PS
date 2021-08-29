#include <iostream>
#include <vector>
using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, ans = 0;  // 15

// 점수 = 사라지는 자동차칸 갯수 + 해당차고를 포함하는 가장 작은 직사각형 면적
void go(vector<vector<int>> map, int point, int cnt) {  // 맵, 얻은 점수, 회차0~2, 3되면 끝
    if (cnt == 3) {
        ans = max(ans, point);
        return;
    }

    bool check[n][n];
    for (int i = 3 * n - n + 1; i < 3 * n; ++i) {
        for (int j = 0; j < n; ++j) {
        }
    }
}

int main(int argc, char** argv) {
    cin >> n;
    vector<vector<int>> a(3 * n, vector<int>(n));
    for (int i = 0; i < 3 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    // backtracking
    go(a, 0, 0);
    cout << ans;
    return 0;
}