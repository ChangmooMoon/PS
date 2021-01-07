#include <iostream>
#include <vector>

using namespace std;

int solution(int k, vector<int>& v) {
    int result = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        result += (k / v[i]);
        k %= v[i];
    }
    return result;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> v(N);  // 배수관계
    for(int i = 0; i<N; ++i){
        cin >> v[i];
    }
    cout << solution(K, v) << endl;
    return 0;
}
