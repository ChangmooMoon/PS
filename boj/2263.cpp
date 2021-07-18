#include <iostream>
#include <vector>
using namespace std;

// 프리오더: 루LR
// 인오더: L루R
// 포스트오더: LR루

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> inorder(n);   // 1 2 3
    vector<int> preorder(n);  // 1 3 2
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        inorder.push_back(val)
    }
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        preorder.push_back(val);
    }

    return 0;
}
