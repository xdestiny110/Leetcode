/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

struct MyElement{
    MyElement(int _x = 0, int _y = 0, bool _flag = true):x(_x), y(_y), flag(_flag){}
    int x = 0;
    int y = 0;
    bool flag = true;
};

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if(word.empty())
            return true;
        if(board.empty() || board[0].empty()){
            return (word == "")?true:false;
        }
        for(int i = 0;i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                record[board[i][j]].emplace_back(i, j, true);
            }
        }
        return DFS(0, word, MyElement());
    }

private:
    std::unordered_map<char, std::vector<MyElement>> record;

    bool isNearBy(const MyElement& a, const MyElement& b) const {
        return (std::abs(a.x - b.x) + std::abs(a.y - b.y) == 1)?true:false;
    }

    bool DFS(int layer, const std::string& word, const MyElement& currentPos){
        if(layer == word.size())
            return true;

        if(record.find(word[layer]) != record.end()){
            for(auto&& it : record[word[layer]]){
                if((layer == 0 || isNearBy(currentPos, it)) && it.flag){
                    it.flag = false;
                    auto flag = DFS(layer+1, word, it);
                    if(flag)
                        return true;
                    it.flag = true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

