#pragma once
#include<string.h>
#include<string>
using std::string;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
        memset(sons, 0, sizeof(sons));
    }
    TrieNode *sons[26];
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *n = root;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (n->sons[index] == nullptr)
                n->sons[index] = new TrieNode();
            n = n->sons[index];
        }
        n->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *n = root;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (n->sons[index])
                n = n->sons[index];
            else
                return false;
        }
        if (n->isEnd)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *n = root;
        for (auto ch : prefix)
        {
            int index = ch - 'a';
            if (n->sons[index])
                n = n->sons[index];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};