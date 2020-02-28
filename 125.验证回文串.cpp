/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start

#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if(s.empty()) return true;
        auto begin = s.begin();
        auto end = s.end() - 1;
        while(std::distance(begin, end) > 0){
            auto b = std::tolower(*begin);
            auto e = std::tolower(*end);
            while(!isNumber(b) && !isLetter(b)){
                begin++;
                b = std::tolower(*begin);
                if(begin == end)
                    return true;
            }
            while(!isNumber(e) && !isLetter(e)){
                end--;
                e = std::towlower(*end);
                if(begin == end)
                    return true;
            }
            if(b != e){
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }

private:
    bool isNumber(char c) const{
        return c >= '0' && c <= '9';
    }

    bool isLetter(char c) const{
        return c <= 'z' && c>= 'a';
    }
};
// @lc code=end

