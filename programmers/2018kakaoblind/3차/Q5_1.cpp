#include <cstring>
#include <string>
#include <vector>
using namespace std;
// tries 트라이
class TrieNode {
  public:
    int overlap;
    TrieNode *child[27];
    TrieNode() {
        overlap = 0;
        memset(child, NULL, sizeof(child));
    };
};

TrieNode *root = new TrieNode();

void insert(string word) {
    TrieNode *node = root;
    for (char ch : word) {
        if (!node->child[ch - 'a']) node->child[ch - 'a'] = new TrieNode();
        node = node->child[ch - 'a'];
        node->overlap++;
    }
}

int cntLen(string word) {
    TrieNode *node = root;
    int depth = 0;

    for (char ch : word) {
        node = node->child[ch - 'a'];
        ++depth;
        if (node->overlap == 1) return depth;
    }

    return depth;
}

int solution(vector<string> words) {
    for (string s : words) {
        insert(s);
    }

    int ans = 0;
    for (string s : words) {
        ans += cntLen(s);
    }
    return ans;
