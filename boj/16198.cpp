#include <iostream>
#include <vector>
using namespace std;

int n;
int go(vector<int>& w) {
    int n = w.size();
    if (n == 2) return 0;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        int energy = w[i - 1] * w[i + 1];

        vector<int> nw(w);
        nw.erase(nw.begin() + i);
        energy += go(nw);
        ans = max(ans, energy);
    }

    return ans;
}

// 케이스 (n-2)! = 8! = 4만
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    cout << go(w);
    return 0;
}
