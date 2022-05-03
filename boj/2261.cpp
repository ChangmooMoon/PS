#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
using namespace std;

// line sweeping
struct Point {
    int x, y;
    bool operator<(const Point &other) const {
        if (y == other.y) return x < other.x;
        return y < other.y;
    }
};

bool cmp(const Point &u, const Point &v) { return u.x < v.x; }

int getDist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int n;
vector<Point> v;
set<Point> s;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    s.insert(v[0]);
    s.insert(v[1]);

    int ans = getDist(v[0], v[1]);
    int start = 0;
    for (int i = 2; i < n; i++) {
        Point now = v[i];

        while (start < i) {
            auto p = v[start];
            int d = (now.x - p.x) * (now.x - p.x);
            if (d > ans) {
                s.erase(p);
                ++start;
            } else
                break;
        }
        int d = (int)sqrt((double)ans) + 1;
        auto lIt = s.lower_bound({-100000, now.y - d});
        auto rIt = s.upper_bound({-100000, now.y + d});
        for (auto it = lIt; it != rIt; it++) {
            int d = getDist(now, *it);
            if (d < ans) ans = d;
        }
        s.insert(now);
    }

    cout << ans;
    return 0;
}
