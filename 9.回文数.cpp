/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        std::string s = std::to_string(x);
        if(s.size() == 1)
            return true;
        int p1 = s.size()/2;
        int p2 = 0;
        if(s.size() & 1)
            p2 = s.size()/2;
        else
            p2 = s.size()/2-1;
        while(p1 < s.size() && p2 >= 0){
            if(s[p1--] != s[p2++])
                return false;
        }
        return true;
    }
};

