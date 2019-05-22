/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ret = m[s[0]];
        for(int i = 1;i < s.size();i++){
            if(m[s[i]] > m[s[i-1]])
                ret += m[s[i]]-2*m[s[i-1]];
            else
                ret += m[s[i]];
        }
        return ret;
    }
};

