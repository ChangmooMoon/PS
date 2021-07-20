#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(-1);
    pq.push(-2);
    pq.push(-3);
    cout << pq.top() << endl;

    return 0;
}