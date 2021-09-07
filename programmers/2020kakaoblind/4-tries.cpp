#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    vector<TrieNode*> children;
    int count;

    TrieNode() : children(ALPHABET_SIZE), count(0) {
    }

    void insert(string& s) {
        TrieNode* curr = this;
        for (char& ch : s) {
            curr->count++;
            int next = ch - 'a';
            if (curr->children[next] == nullptr) {
                curr->children[next] = new TrieNode();
            }

            curr = curr->children[next];
        }

        curr->count++;
    }

    int search(string& s) {
        TrieNode* curr = this;
        int count = 0;
        for (char& ch : s) {
            if (ch == '?') {
                count = curr->count;
                break;
            }

            curr = curr->children[ch - 'a'];
            if (curr == nullptr) {
                break;
            }
        }

        return count;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    TrieNode TrieRoot[10001];
    TrieNode ReverseTrieRoot[10001];

    for (string& w : words) {
        int len = w.length();
        TrieRoot[len - 1].insert(w);
        reverse(w.begin(), w.end());
        ReverseTrieRoot[len - 1].insert(w);
    }

    for (string& q : queries) {
        int ans;
        int len = q.length();
        if (q[0] == '?') {
            reverse(q.begin(), q.end());
            ans = ReverseTrieRoot[len - 1].search(q);
        } else {
            ans = TrieRoot[len - 1].search(q);
        }
        answer.push_back(ans);
    }

    return answer;
}
