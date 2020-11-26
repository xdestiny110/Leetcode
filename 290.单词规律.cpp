/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> splitStr;
        int head = -1;
        bool flag = false;
        for(int i = 0; i < s.size(); ++i){
            if(!flag && s[i] != ' ') {
                head = i;
                flag = true;
            }
            if(head >= 0 && s[i] == ' ' && flag){
                splitStr.push_back(s.substr(head, i - head));
                flag = false;
            }
        }
        if(flag){
            splitStr.push_back(s.substr(head, s.size() - head));
        }

        if(splitStr.size() != pattern.size()) return false;

        std::unordered_map<char, std::string> m0;
        std::unordered_map<std::string, char> m1;
        for(int i = 0; i < pattern.size(); ++i){
            auto it0 = m0.find(pattern[i]);
            if(it0 == m0.end()){
                m0[pattern[i]] = splitStr[i];
            }
            else{
                if(it0->second != splitStr[i]) return false;
            }

            auto it1 = m1.find(splitStr[i]);
            if(it1 == m1.end()){
                m1[splitStr[i]] = pattern[i];
            }
            else{
                if(it1->second != pattern[i]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

