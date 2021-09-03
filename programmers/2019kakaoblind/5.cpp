// 길찾기 게임(트리 순회)
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int idx, x, y;
    Node* left;
    Node* right;

    bool operator<(const Node& other) const {  // y내림차순 루트, x는 오름차순
        if (y == other.y) return x < other.x;
        return y > other.y;
    }
};

vector<Node> tree;
vector<vector<int>> answer(2);  // 전위, 후위순회 결과

void insert(Node* parent, Node* child) {
    if (child->x < parent->x) {  // child가 더 왼쪽이면
        if (parent->left == NULL)
            parent->left = child;
        else
            insert(parent->left, child);
    } else {  // child와 같거나 오른쪽이면
        if (parent->right == NULL)
            parent->right = child;
        else
            insert(parent->right, child);
    }
}

void visit(Node* node, vector<int>& v) {
    v.push_back(node->idx);
    return;
}

void preorder(Node* node) {  // 루트-L-R
    if (node == NULL) return;

    visit(node, answer[0]);
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {  // L-R-루트
    if (node == NULL) return;

    postorder(node->left);
    postorder(node->right);
    visit(node, answer[1]);
}

// 1. 트리 리스트로 그린다 2.ans[0]은 preorder, ans[1]은 postorder 순회순서 넣기
// y가 크면 root 내림차순, x는 오름차순대로 idx
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int len = nodeinfo.size();
    tree.resize(len);

    for (int i = 0; i < len; ++i) {
        tree[i] = {i + 1, nodeinfo[i][0], nodeinfo[i][1]};
    }
    sort(tree.begin(), tree.end());

    Node* root = &tree[0];
    for (int i = 1; i < len; ++i) {
        insert(root, &tree[i]);
    }

    preorder(root);
    postorder(root);

    return answer;
}
