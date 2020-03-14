/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

#include <unordered_map>

struct Node{
    std::unordered_map<char, Node*> m;
    bool isEnd = false;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        dictTree = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto* n = dictTree;
        for(const auto& it : word){
            if(n->m.find(it) == n->m.end()){
                auto* nn = new Node();
                n->m[it] = nn;
                n = nn;
            }
            else{
                n = n->m[it];
            }
        }
        n->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* n = dictTree;
        for(const auto& it : word){
            auto jt = n->m.find(it);
            if(jt == n->m.end()){
                return false;
            }
            else{
                n = jt->second;
            }
        }
        if(n->isEnd) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto* n = dictTree;
        for(const auto& it : prefix){
            auto jt = n->m.find(it);
            if(jt == n->m.end()){
                return false;
            }
            else{
                n = jt->second;
            }
        }
        return true;
    }

private:
    Node* dictTree = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

