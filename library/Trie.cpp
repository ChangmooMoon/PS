#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Trie {
    bool finish;
    Trie* next[26];
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    void insert(const char* key) {
        if ((*key) == '\0') {
            finish = true;
            return;
        };
        int curr = (*key) - 'a';
        if (!next[curr])
            next[curr] = new Trie();
        next[curr]->insert(key + 1);
    }

    bool find(const char* key) {
        if ((*key) == '\0')
            return true;
        int curr = (*key) - 'a';
        if (!next[curr])
            return false;
        return next[curr]->find(key + 1);
    }
};