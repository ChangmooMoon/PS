#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Fish {
    int r, c, dir;
    bool isAlive;
};

vector<Fish> fishList(17);                     // 상어idx0~15 저장
vector<vector<int>> board(4, vector<int>(4));  // 물고기 위치별로 idx 저장
int sharkDir, sharkEat;                        // 상어방향, 상어먹은물고기인덱스합

void solve(int sr, int sc, int sDir, int eat, vector<Fish> fList, vector<vector<int>> map) {
    // 1. 물고기 이동
    for (Fish& fish : fList) {
        const auto& [r, c, dir, isAlive] = fish;

        if (!isAlive) continue;
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nDir = (dir + i) % 8;
            if (0 > nr || 0 > nc || nr <= 4 || nc <= 4) continue;
            if (map[nr][nc] == 17) continue;

            swap(map[nr][nc], map[r][c]);
            cout << endl;
            swap(fList[map[nr][nc]], fList[map[r][c]]);
        }
    }

    // 2. 상어 이동
    bool sharkEatFood = true;
    int nsr = sr + dr[sDir], nsc = sc + dc[sDir];

    while (0 <= nsr && 0 <= nsc && nsr < 4 && nsc < 4) {  // 0,1,2,3
        vector<Fish> fList_cpy = fList;
        vector<vector<int>> map_cpy = map;

        if (map_cpy[nsr][nsc] > 0) {
            int fIdx = map_cpy[nsr][nsc];
            fList_cpy[fIdx].isAlive = false;
            map_cpy[sr][sc] = 0;
            map_cpy[nsr][nsc] = 17;
            solve(nsr, nsc, fList_cpy[fIdx].dir, eat + fIdx, fList_cpy, map_cpy);
            sharkEatFood = false;
        }

        nsr += dr[sDir];
        nsc += dc[sDir];
    }

    if (sharkEatFood) {
        sharkEat = max(sharkEat, eat);
        return;
    }

    return;
}

int main() {
    FASTIO;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int idx, dir;
            cin >> idx >> dir;
            --dir;
            fishList[idx] = {i, j, dir, true};
            board[i][j] = idx;
        }
    }

    sharkDir = fishList[board[0][0]].dir;
    fishList[board[0][0]].isAlive = false;
    sharkEat += board[0][0];
    board[0][0] = 17;  // 상어 idx 17

    solve(0, 0, sharkDir, sharkEat, fishList, board);
    cout << sharkEat;
    return 0;
}
