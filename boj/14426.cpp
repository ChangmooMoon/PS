#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tries {
    struct Node {
        int child[26];
        bool valid;

        Node() {
            for (int i = 0; i < 26; ++i) {
                child[i] = -1;
            }
            valid = false;
        }
    };

    vector<Node> trie;
    int root;
    int init() {
        Node x;
        trie.push_back(x);
        return (int)trie.size() - 1;
    }

    Tries() {
        root = init();
    }

    void add(int node, string& s, int index) {
        if (index == s.size()) {
            trie[node].valid = true;
            return;
        }

        int c = s[index] - 'a';
        if (trie[node].child[c] == -1) {
            int next = init();
            trie[node].child[c] = next;
        }

        int child = trie[node].child[c];
        add(child, s, index + 1);
    }

    void add(string& s) {
        add(root, s, 0);
    }

    bool search(int node, string& s, int index) {
        if (node == -1) return false;
        if (index == s.length()) return true;

        int c = s[index] - 'a';
        int child = trie[node].child[c];
        return search(child, s, index + 1);
    }

    bool search(string& s) {
        return search(root, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = 0;
    int n, m;
    cin >> n >> m;
    Tries trie;
    while (n--) {
        string s;
        cin >> s;
        trie.add(s);
    }

    while (m--) {
        string s;
        cin >> s;
        if (trie.search(s)) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}
