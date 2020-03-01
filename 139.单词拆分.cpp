/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct pairHash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        return DFS(s, wordDict, 0, s.size());
    }

private:
    std::unordered_set<std::pair<int, int>, pairHash> recordTrue;
    std::unordered_set<std::pair<int, int>, pairHash> recordFalse;

    bool DFS(const std::string& s, std::vector<std::string>& wordDict, int start, int end){
        for(int i = end; i > 0; i--){
            auto t0 = s.substr(start, i - start);
            if (recordFalse.find({start, i}) == recordFalse.end() && ((recordTrue.find({start, i}) != recordTrue.end())) ||
                (std::find(wordDict.begin(), wordDict.end(), t0) != wordDict.end())){
                recordTrue.emplace(start, i);
                auto t1 = s.substr(i, end - i);
                if(t1.empty()) return true;
                auto flag = recordFalse.find({i, end}) == recordFalse.end() && ((recordTrue.find({i, end}) != recordTrue.end()) || DFS(s, wordDict, i, end));
                if(flag){
                    recordTrue.emplace(i, end);
                    return true;
                }
                else{
                    recordFalse.emplace(i, end);
                }
            }
            else{
                recordFalse.emplace(start, i);
            }
        }
        return false;
    }
};
// @lc code=end

