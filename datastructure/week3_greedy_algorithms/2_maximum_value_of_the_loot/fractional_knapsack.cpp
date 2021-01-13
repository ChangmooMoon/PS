#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int size = weights.size();
    vector<pair<double, int>> v(size);
    for(int i = 0; i< size; ++i){
        v[i] = make_pair((double)values[i]/weights[i], i);
    }
    sort(v.begin(), v.end());

    for(int i = size-1; i>=0; --i){
        if(capacity == 0)
            return value;
        if(weights[v[i].second] >= capacity){
            value += v[i].first * (double)capacity;
            capacity = 0;
        } else {
            value += values[v[i].second];
            capacity -= weights[v[i].second];
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
