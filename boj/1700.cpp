#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, k, ans;
int a[101];
bool check[101];
vector<int> plug;

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        if (!check[a[i]]) {
            if (plug.size() < n) {
                check[a[i]] = true;
                plug.push_back(a[i]);
            } else { // plug.size() == n
                int idx = 0, mdist = 0;
                for (int j = 0; j < n; ++j) {
                    int dist = 0;
                    for (int p = i + 1; p < k; ++p) {
                        if (a[p] == plug[j]) break;
                        ++dist;
                    }
                    if (dist > mdist) {
                        idx = j;
                        mdist = dist;
                    }
                }
                check[plug[idx]] = false;
                check[a[i]] = true;
                plug[idx] = a[i];
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
