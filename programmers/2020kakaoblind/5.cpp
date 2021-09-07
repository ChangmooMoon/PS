#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool col[102][102] = {0};  // 기둥
bool row[102][102] = {0};  // 보

bool checkCol(int x, int y) {                 // 가로세로
    if (y == 0) return true;                  // 바닥
    if (col[x][y - 1]) return true;           // 밑에 기둥 있음
    if (x > 0 && row[x - 1][y]) return true;  // 바닥이 아니고 보가 왼쪽에서 오른쪽으로 오면
    if (row[x][y]) return true;               // 밑에 보가 있으면

    return false;
}

bool checkRow(int x, int y) {
    if (col[x][y - 1] || col[x + 1][y - 1]) return true;       // 왼쪽이나 오른쪽 밑에 기둥 있음
    if (x > 0 && row[x - 1][y] && row[x + 1][y]) return true;  // 왼쪽 오른쪽에 보가 있어서 그 사이에 연결

    return false;
}

bool canRemove(int x, int y) {
    for (int i = max(0, x - 1); i <= x + 1; ++i) {
        for (int j = y; j <= y + 1; ++j) {
            if (col[i][j] && !checkCol(i, j)) return false;
            if (row[i][j] && !checkRow(i, j)) return false;
        }
    }

    return true;
}

// build_frame [x,y,a,b] 가로,세로,기둥보01, 삭제설치01
// answer [x,y,a] xy기둥보교차좌표, 기둥보01, x,y가 같으면 기둥-보 순
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (vector<int>& frame : build_frame) {
        int x, y, type, action;
        x = frame[0], y = frame[1], type = frame[2], action = frame[3];

        if (type == 0) {
            if (action == 1) {
                if (checkCol(x, y)) col[x][y] = true;
            } else {
                col[x][y] = false;
                if (!canRemove(x, y)) col[x][y] = true;
            }
        } else {
            if (action == 1) {
                if (checkRow(x, y)) row[x][y] = true;
            } else {
                row[x][y] = false;
                if (!canRemove(x, y)) row[x][y] = true;
            }
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (col[i][j]) ans.push_back({i, j, 0});
            if (row[i][j]) ans.push_back({i, j, 1});
        }
    }

    return ans;
}
