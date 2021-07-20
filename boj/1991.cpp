#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char left, right;
};
vector<Node> tree[26];  // A~Z

void preorder(char root) {
    Node rootNode = tree[root - 'A'].front();
    char left = rootNode.left;
    char right = rootNode.right;

    cout << root;
    if (left != '.') preorder(left);
    if (right != '.') preorder(right);
}

void inorder(char root) {
    Node rootNode = tree[root - 'A'].front();
    char left = rootNode.left;
    char right = rootNode.right;

    if (left != '.') inorder(left);
    cout << root;
    if (right != '.') inorder(right);
}

void postorder(char root) {
    Node rootNode = tree[root - 'A'].front();
    char left = rootNode.left;
    char right = rootNode.right;

    if (left != '.') postorder(left);
    if (right != '.') postorder(right);
    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'].push_back({left, right});
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

    return 0;
}

// inorder : 왼루오
// preorder : 루왼오
// postorder : 왼오루