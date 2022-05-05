#include <queue>
#include <vector>
using namespace std;
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int rotD[2][4][2] = {{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}, {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}}};
int cornerD[2][4][2] = {{{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}, {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}};

struct Pos {
    int r, c, dir, time;
};

int N;
vector<vector<int>> Board;
queue<pair<Pos, Pos>> q;
bool check[101][101][4] = {false}; // 상우하좌

bool isValid(Pos nxt[2]) {
    for (int i = 0; i < 2; ++i) {
        if (nxt[i].r < 0 || nxt[i].c < 0 || N <= nxt[i].r || N <= nxt[i].c) return false;
        if (Board[nxt[i].r][nxt[i].c]) return false;
        if (check[nxt[i].r][nxt[i].c][nxt[i].dir]) return false;
    }

    return true;
}

int rotate(Pos now[2], int ccw, int axis) { // {fi, se}, 0 or 1, fi or se축
    Pos nxt[2];
    int fi = axis, se = (axis + 1) % 2;
    int dir = now[fi].dir;

    nxt[0] = {now[fi].r, now[fi].c, (now[fi].dir + (ccw ? 3 : 1)) % 4, now[fi].time + 1};
    nxt[1] = {now[se].r + rotD[ccw][dir][0], now[se].c + rotD[ccw][dir][1],
              (now[se].dir + (ccw ? 3 : 1)) % 4, now[fi].time + 1};

    if (!isValid(nxt)) return 0;
    if (Board[now[fi].r + cornerD[ccw][dir][0]][now[fi].c + cornerD[ccw][dir][1]]) return 0;

    for (int i = 0; i < 2; ++i) {
        if (nxt[i].r == N - 1 && nxt[i].c == N - 1) return nxt[i].time;
        check[nxt[i].r][nxt[i].c][nxt[i].dir] = true;
    }
    q.push({nxt[fi], nxt[se]});
    return 0;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    Board = board;

    q.push({Pos{0, 0, RIGHT, 0}, Pos{0, 1, LEFT, 0}});
    check[0][0][RIGHT] = check[0][1][LEFT] = true;

    while (!q.empty()) {
        Pos now[2], nxt[2];
        now[0] = q.front().first;
        now[1] = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {     // dir
            for (int j = 0; j < 2; ++j) { // fi, se
                nxt[j] = {now[j].r + dr[i], now[j].c + dc[i], now[j].dir, now[j].time + 1};
            }

            if (!isValid(nxt)) continue;

            for (int j = 0; j < 2; ++j) {
                if (nxt[j].r == N - 1 && nxt[j].c == N - 1) return nxt[j].time;
                check[nxt[j].r][nxt[j].c][nxt[j].dir] = true;
            }
            q.push({nxt[0], nxt[1]});
        }

        for (int ccw = 0; ccw < 2; ++ccw) { // 회전 방향
            for (int i = 0; i < 2; ++i) {   // 축 선택
                int ret = rotate(now, ccw, i);
                if (ret) return ret;
            }
        }
    }

    return -1;
}
