/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        if(std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        std::queue<std::pair<int, std::string>> q;
        q.push({0, std::move(beginWord)});
        while(!q.empty()){
            auto& node = q.front();
            for(auto it = wordList.begin(); it != wordList.end();){
                if(canChange(node.second, *it)){
                    if(*it == endWord){
                        return node.first + 2;
                    }
                    q.push({node.first + 1, std::move(*it)});
                    it = wordList.erase(it);
                }
                else{
                    ++it;
                }
            }
            q.pop();
        }
        return 0;
    }

private:
    bool canChange(const std::string& s1, const std::string& s2) const{
        int cnt = 0;
        for(int i = 0;i < s1.size(); ++i){
            if(s1[i] != s2[i]){
                cnt++;
            }
            if(cnt > 1)
                return false;
        }
        return cnt == 1;
    }
};
// @lc code=end

