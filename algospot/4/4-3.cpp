#include <iostream>
#include <vector>

using namespace std;

vector<double> movingAverage1(const vector<double>& A, int M) {
    vector<double> ret; // 이동평균 부분집합의 크기 M
    int N = A.size();

    for (int i = M - 1; i < N; ++i) { // 
        double partialSum = 0;
        for (int j = 0; j < M; ++j) {
            partialSum += A[i - j]; // 3개 측정치의 합을 구해서
        }
        ret.push_back(partialSum / M); // 3으로 나눈다
    }
    return ret;
}

int main() {
    vector<double> point{10, 20, 30.5, 40.5, 50.9};
    point = movingAverage1(point, 3);
    for(auto i: point) {
      cout << i << endl;
    }
}
