/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int currentLen = 0;
        bool flag = true;
        for(const auto& c : s){
            if(c != ' '){
                currentLen = flag?1:currentLen+1;
                flag = false;
            }
            else
                flag = true;
        }

        return currentLen;
    }
};

