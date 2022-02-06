#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int num;  // 약수의 갯수50
int main() {
    FASTIO;
    cin >> num;

    int d[num];
    for (int i = 0; i < num; ++i) {
        cin >> d[i];
    }
    sort(d, d + num);

    cout << d[0] * d[num - 1];
    return 0;
}
