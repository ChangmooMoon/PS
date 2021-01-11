#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long long edge[100000];
long long price[100001];

long long solve(int n) {
    long long oil = LLONG_MAX;
    long long result = 0;
    for (int i = 1; i <= n - 1; ++i) {
        if (price[i] < oil) {
            oil = price[i];
        }
        result += oil * edge[i];
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; ++i) {
        cin >> edge[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> price[i];
    }

    cout << solve(N) << endl;
    return 0;
}