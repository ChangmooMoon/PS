#include <iostream>
#include <vector>
using namespace std;

int in[100001];
int post[100001];
int idx[100001];

// pre 루-왼-오
// in 왼-루-오
// post 왼-오-루

// preorder 출력
void print(int inStart, int postStart, int size) {
    if (size == 0) return;
    if (size == 1) {
        cout << post[postStart] << ' ';
        return;
    }

    int root = post[postStart + size - 1];  // post 마지막 노드가 inorder root
    int rootIdx = idx[root];
    int leftSize = rootIdx - inStart;
    int rightSize = size - leftSize - 1;  // 전체 사이즈 - 왼쪽서브트리 - 루트 = 오른쪽서브트리

    cout << root << ' ';
    print(inStart, postStart, leftSize);
    print(rootIdx + 1, postStart + leftSize, rightSize);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        idx[in[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }

    print(0, 0, n);
    return 0;
}
