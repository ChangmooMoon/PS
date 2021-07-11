#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    // long long x = 1e10;
    // cout << (x > 1e9) << endl;

    // unordered_map<int, int> umap;
    // umap[1] = 2;
    // cout << umap[1] << endl;  //2
    // cout << umap[2] << endl;  //0
    // ++umap[1];
    // ++umap[2];
    // cout << umap[1] << endl;  //3
    // cout << umap[2] << endl;  //1
    priority_queue<pair<int, int>> pq;
    pq.push({1, 2});
    pq.push({3, 4});
    pq.push({5, 6});
    // const auto& [a, b] = pq.top();
    // pq.pop();
    // cout << a << b << endl;
    for (int i = 0; i < pq.size() * 2; ++i) {
        cout << i << endl;
    }

    return 0;
}