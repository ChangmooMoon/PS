#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

struct Pos {
    int rr, rc, br, bc, cnt;
};

queue<Pos> q;
string board[10];
bool visit[10][10][10][10];
int n, m;

void bfs() {
    while (!q.empty()) {
        int rr = q.front().rr;
        int rc = q.front().rc;
        int br = q.front().br;
        int bc = q.front().bc;
        int cnt = q.front().cnt;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrr = rr;
            int nrc = rc;
            bool redchk = false;
            bool bluechk = false;

            while (1) {
                nrr += dr[i];
                nrc += dc[i];

                if (board[nrr][nrc] == '#') {
                    nrr -= dr[i];
                    nrc -= dc[i];
                    break;
                } else if (board[nrr][nrc] == 'O') {
                    redchk = true;
                    break;
                }
            }

            int nbr = br;
            int nbc = bc;

            while (1) {
                nbr += dr[i];
                nbc += dc[i];

                if (board[nbr][nbc] == '#') {
                    nbr -= dr[i];
                    nbc -= dc[i];
                    break;
                } else if (board[nbr][nbc] == 'O') {
                    bluechk = true;
                    break;
                }
            }

            if (bluechk)
                continue;
            else if (redchk) {
                cout << cnt + 1;
                return;
            }

            if (nrr == nbr && nrc == nbc) {
                int reddis = abs(nrr - rr) + abs(nrc - rc);
                int bluedis = abs(nbr - br) + abs(nbc - bc);

                if (reddis > bluedis) {
                    nrr -= dr[i];
                    nrc -= dc[i];
                } else {
                    nbr -= dr[i];
                    nbc -= dc[i];
                }
            }

            if (visit[nrr][nrc][nbr][nbc]) continue;

            q.push({nrr, nrc, nbr, nbc, cnt + 1});
            visit[nrr][nrc][nbr][nbc] = true;
        }
    }

    cout << -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int rr, rc, br, bc;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'B') {
                br = i;
                bc = j;
            } else if (board[i][j] == 'R') {
                rr = i;
                rc = j;
            }
        }
    }

    q.push({rr, rc, br, bc, 0});
    visit[rr][rc][br][bc] = true;
    bfs();

    return 0;
}
