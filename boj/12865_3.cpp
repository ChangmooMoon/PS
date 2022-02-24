#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, k;
int w[101], v[101], d[100001]; // d[i] = i무게 가치의 최대
// d[j] = max(d[j- w[i]] + v[i])

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= w[i]; --j) {
            d[j] = max(d[j], d[j - w[i]] + v[i]);
        }
    }

    cout << d[k];
    return 0;
}
