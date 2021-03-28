#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int n, k, t;
    Pos(int _n, int _k, int _t) : n(_n), k(_k), t(_t) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MAX = 500'000;

    int n, k;
    int ans = -1;
    cin >> n >> k;

    vector<vector<bool>> visit(MAX + 1, vector<bool>(2));
    queue<Pos> q;
    q.push(Pos(n, k, 0));

    while (!q.empty()) {
        
    }

    cout << ans;
    return 0;
}
