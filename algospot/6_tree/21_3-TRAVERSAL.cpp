#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostorder(const vector<int>& preorder, const vector<int>& inorder) {
    if (preorder.empty()) return;

    int N = preorder.size();
    int root = preorder[0];
    int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int R = N - L - 1;

    printPostorder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
    printPostorder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

    cout << root << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> preorder, inorder;
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            preorder.push_back(val);
        }
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            inorder.push_back(val);
        }

        printPostorder(preorder, inorder);
        cout << endl;
    }

    return 0;
}

// inorder: 왼루오
// preorder: 루왼오
// postorder: 왼오루