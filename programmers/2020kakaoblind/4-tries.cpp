#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class TrieNode {
  public:
    bool end;
    TrieNode *child[27];
    TrieNode() {
        end = false;
        memset(child, NULL, sizeof(child));
    }
};

TrieNode *root = new TrieNode(); /* Root Creation */

void insert(string word) { /* Insert word into the trie */
    TrieNode *node = root;
    for (char c : word) {
        if (!node->child[c - 'a']) { node->child[c - 'a'] = new TrieNode(); }
        node = node->child[c - 'a'];
    }
    node->end = true;
}

bool search(string word) { /* Search word into the trie */
    TrieNode *node = root;
    for (char c : word) {
        if (!node->child[c - 'a']) { return false; }
        node = node->child[c - 'a'];
    }
    return node->end;
}