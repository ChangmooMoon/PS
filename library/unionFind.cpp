#include <iostream>
#define union _union
using namespace std;

int parent[11];

int find(int x) {  // 부모찾기
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union(int a, int b) {  // 각 부모 노드를 합친다
    a = find(a);
    b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool sameParent(int a, int b) {  // 같은 부모 노드인지 확인한다
    a = find(a);
    b = find(b);
    if (a == b) return true;
    return false;
}

int main() {
    for (int i = 0; i < 11; ++i) {
        parent[i] = i;
    }

    union(1, 2);
    union(2, 3);
    union(3, 4);
    union(5, 6);
    union(6, 7);
    union(7, 8);
    cout << sameParent(1, 5) << endl;
    union(1, 5);
    cout << sameParent(1, 5) << endl;
}