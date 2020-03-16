/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
#include <unordered_map>
#include <string>

struct Node{
    std::unordered_map<char, Node*> m;
    bool isEnd = false;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(std::string word) {
        auto* n = root;
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(std::string word) {
        return DFS(word, 0, root);
    }
private:
    Node* root = nullptr;

    bool DFS(const std::string& word, int layer, Node* n){
        if(layer >= word.size()) return n->isEnd;
        if(word[layer] != '.'){
            if(n->m.find(word[layer]) == n->m.end())
                return false;
            return DFS(word, layer+1, n->m[word[layer]]);
        }
        for(const auto& [k, v] : n->m){
            if(DFS(word, layer+1, v))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

