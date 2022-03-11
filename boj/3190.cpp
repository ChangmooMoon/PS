#include <deque>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, k, l, a[101][101]; // 0빈칸 1뱀 2사과
vector<pair<int, char>> v;

int move() { // 끝나는 시간 리턴
    deque<pair<int, int>> q;
    int t = 0, p = 0, dir = 1;
    q.push_back({1, 1});
    while (1) {
        ++t;
        int r, c;
        tie(r, c) = q.front();

        int nr = r + dr[dir], nc = c + dc[dir];
        if (0 >= nr || 0 >= nc || n < nr || n < nc || a[nr][nc] == 1) break;

        q.push_front({nr, nc});
        if (a[nr][nc] == 0) { // 사과없으면 pop
            int br, bc;
            tie(br, bc) = q.back();
            a[br][bc] = 0;
            q.pop_back();
        }
        a[nr][nc] = 1;
        if (v[p].first == t) {
            if (v[p].second == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;

            ++p;
        }
    }
    return t;
}

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        a[r][c] = 2;
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
        int x;
        char d;
        cin >> x >> d;
        v.push_back({x, d});
    }
    cout << move();
    return 0;
}
