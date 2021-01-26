#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int d[] = {1, 2, 3, 4, 5};

int n;         // 3~6
char a[7][7];  // X, S, T
char backup[7][7];
vector<pair<int, int> > zPos;
vector<int> permu;
int teacherNum = 0;

bool checkUDLR(int x, int y) {  // n*n에서 상5하5좌5우5 체크
    int nx, ny;
    for (int i = 0; i < 5; ++i) {  // 오른쪽
        nx = x + d[i];
        if (nx < n) {
            if (a[nx][y] == 'O') {
                break;
            }
            if (a[nx][ny] == 'S') return false;
        }
    }

    for (int i = 0; i < 5; ++i) {  // 왼쪽
        nx = x - d[i];
        if (0 <= nx) {
            if (a[nx][y] == 'O') {
                break;
            }
            if (a[nx][y] == 'S') return false;
        }
    }

    for (int i = 0; i < 5; ++i) {  // 위
        ny = y + d[i];
        if (0 <= ny) {
            if (a[nx][ny] == 'O') {
                break;
            }
            if (a[x][ny] == 'S') return false;
        }
    }

    for (int i = 0; i < 5; ++i) {  // 아래
        ny = y - d[i];
        if (ny < n) {
            if (a[x][ny] == 'O') {
                break;
            }
            if (a[x][ny] == 'S') return false;
        }
    }
    return true;  // true면 숨기성공, false면 숨기 실패
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'X')
                zPos.push_back({i, j});
            if (a[i][j] == 'T')
                teacherNum++;
        }
    }

    for (int i = 0; i < 3; ++i)
        permu.push_back(1);
    for (int i = 0; i < zPos.size() - 3; ++i)
        permu.push_back(0);

    memcpy(backup, a, sizeof(a));
    do {
        memcpy(a, backup, sizeof(a));
        for (int i = 0; i < permu.size(); ++i) {
            if (permu[i] == 1) {
                auto nx = zPos[i].first;
                auto ny = zPos[i].second;
                a[nx][ny] = 'O';
            }
        }
        // if (a[1][4] == 'O' && a[2][2] == 'O' & a[3][3] == 'O') {
        //     for (int i = 1; i <= n; ++i) {
        //         for (int j = 1; j <= n; ++j) {
        //             cout << a[i][j] << ' ';
        //         }
        //         cout << endl;
        //     }
        // }

        int hide = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == 'T') {
                    if (checkUDLR(i, j)) {
                        hide++;
                    }
                }
            }
        }

        if (hide == teacherNum) {
            cout << "Yes";
            return 0;
        }
    } while (prev_permutation(permu.begin(), permu.end()));

    cout << "NO";
    return 0;
}
