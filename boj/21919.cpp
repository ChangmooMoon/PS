#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, x;
vector<int> pList;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (isPrime(x)) pList.push_back(x);
    }

    if (pList.empty())
        cout << -1;
    else {
        long long ret = pList[0];
        for (int i = 1; i < pList.size(); ++i) {
            ret = lcm(ret, pList[i]);
        }
        cout << ret;
    }
    return 0;
}
