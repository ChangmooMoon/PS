#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 정렬된 벡터에서 중복되는 값 제거
int n, a[1000001];
vector<int> v;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
        cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << ' ';
    }
    return 0;
}