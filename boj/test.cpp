#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct Man {
    int d, h, line;
    bool isMe;
    bool operator<(const Man& other) const {
        if (d == other.d) {
            if (h == other.h) return line > other.line;
            return h < other.h;
        }
        return d < other.d;
    }
};

int main() {
    // int a[] = {1, 2, 4, 5};
    // cout << *lower_bound(a, a + 3, 3) << endl;
    // cout << *upper_bound(a, a + 3, 4);

    // vector<int> v{-3, -1, -5, 0};
    // sort(v.begin(), v.end());
    // for (int a : v) {
    //     cout << a << ' ';
    // }

    priority_queue<Man> pq;
    pq.push({100, 200, 300, false});
    pq.push({50, 100, 200, false});

    Man man = pq.top();
    cout << man.d << ' ' << endl;
    pq.pop();
    man = pq.top();
    cout << man.d << ' ' << endl;
}