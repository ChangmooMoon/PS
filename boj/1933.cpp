#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#define pii pair<int, int>
using namespace std;

vector<pii> vertical;  // 높이가 변하는 지점
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, h, r;
        cin >> l >> h >> r;
        vertical.push_back({l, h});
        vertical.push_back({r, -h});
    }
    sort(vertical.begin(), vertical.end());

    set<int> mset;   // 높이 체크
    mset.insert(0);  // 0 시작
    int nx = vertical[0].first;
    int ny = 0;

    int i = 0;  // 2*n개의 페어까지 카운트하면 종료
    while (i < 2 * n) {
        while (nx == vertical[i].first) {
            int h = vertical[i].second;
            if (h < 0) {
                mset.erase(mset.find(-h));
            } else {
                mset.insert(h);
            }
            ++i;
        }

        int val = *mset.rbegin();  // 카운트되는 건물 중에 제일 큰 높이
        if (val != ny) {
            cout << nx << ' ' << *mset.rbegin() << ' ';
            ny = val;
        }
        nx = vertical[i].first;
    }

    return 0;
}
