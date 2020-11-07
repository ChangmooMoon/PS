#include <iostream>
#include <vector>

using namespace std;

vector<double> movingAverage2(const vector<double>& A, int M) {
    vector<double> ret;

    int N = A.size();
    double pSum = 0;
    for (int i = 0; i < M - 1; ++i) {
        pSum += A[i];
    }
    for (int i = M - 1; i < N; ++i) {
        pSum += A[i];
        ret.push_back(pSum / M);
        pSum -= A[i - M + 1];  // M-1 + N-M+1 = N
    }
    return ret;
}

int main() {
    vector<double> v{1, 3, 2, 4, 3, 5, 4, 6, 5, 1, 1, 5};

    v = movingAverage2(v, 5);
    for (auto i : v) {
        cout << i << endl;
    }
}
